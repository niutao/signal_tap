#include "UsbDetector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <QtCore>
#include <QtCore/QStringList>
#include <QtCore/QCoreApplication>
#include <tchar.h>
#include <Windows.h>
#include <cfgmgr32.h>
#include <setupapi.h>
#include "st_usb.h"

#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#include <dbt.h>

#ifndef DBT_CUSTOMEVENT
#define DBT_CUSTOMEVENT 0x8006
#endif

UsbDetector::UsbDetector(QObject *parent):
    QObject(parent)
{
    mDevNotify = 0;
}

UsbDetector::~UsbDetector()
{
    stopDetector();
}
static void UpdateDevice(PDEV_BROADCAST_DEVICEINTERFACE pDevInf, WPARAM wParam)
{

    // dbcc_name:
    // \\?\USB#Vid_04e8&Pid_503b#0002F9A9828E0F06#{a5dcbf10-6530-11d2-901f-00c04fb951ed}
    // convert to
    // USB\Vid_04e8&Pid_503b\0002F9A9828E0F06
    if (lstrlen(pDevInf->dbcc_name) <= 4)
        return;

    char buffer[128];
    lstrcpyA(buffer, (char *)pDevInf->dbcc_name);

    qDebug("INFO = %s", buffer);
#if 0
    DWORD dwFlag = DBT_DEVICEARRIVAL != wParam
        ? DIGCF_ALLCLASSES : (DIGCF_ALLCLASSES | DIGCF_PRESENT);
    HDEVINFO hDevInfo = SetupDiGetClassDevs(NULL,  NULL, dwFlag);

        if (szDevId == buf) {
            // device found
            if (SetupDiGetDeviceRegistryProperty(hDevInfo, pspDevInfoData,
                SPDRP_FRIENDLYNAME, &DataT, (PBYTE)buf, sizeof(buf), &nSize)) {
                // do nothing
            } else if (SetupDiGetDeviceRegistryProperty(hDevInfo, pspDevInfoData,
                SPDRP_DEVICEDESC, &DataT, (PBYTE)buf, sizeof(buf), &nSize)) {
                // do nothing
            } else {
                lstrcpy(buf, _T("Unknown"));
            }
            // update UI
            break;
        }
    }

    if (pspDevInfoData)
        HeapFree(GetProcessHeap(), 0, pspDevInfoData);
    SetupDiDestroyDeviceInfoList(hDevInfo);
#endif
#define ST_ID_VENDOR  0x04b4
#define ST_ID_PRODUCT 0x1004
    struct st_usb *g_stu;
    int ret;
    g_stu = st_usb_init();
    ret = st_usb_find_device(g_stu, ST_ID_VENDOR, ST_ID_PRODUCT);
    qDebug("errno = %d", ret);
    if (ret != 0)
        return;

    ret = st_usb_open(g_stu);
    char des[128];
    usb_get_string_simple(g_stu->handle, USB_DT_DEVICE, des, 128);
    st_usb_exit(g_stu);

    qDebug("des = %s", des);
}
/*
 http://msdn.microsoft.com/en-us/library/windows/desktop/aa363246%28v=vs.85%29.aspx
typedef struct _DEV_BROADCAST_HDR {
  DWORD dbch_size;
  DWORD dbch_devicetype;
  DWORD dbch_reserved;
} DEV_BROADCAST_HDR, *PDEV_BROADCAST_HDR;

dbch_size:
    The size of this structure, in bytes.
    If this is a user-defined event, this member must be the size of this header, plus the size of the variable-length data in the _DEV_BROADCAST_USERDEFINED structure.
dbch_devicetype:
    The device type, which determines the event-specific information that follows the first three members. This member can be one of the following values.
    Value    Meaning
    DBT_DEVTYP_DEVICEINTERFACE 0x00000005
    Class of devices. This structure is a DEV_BROADCAST_DEVICEINTERFACE structure.
    DBT_DEVTYP_HANDLE 0x00000006
    File system handle. This structure is a DEV_BROADCAST_HANDLE structure.
    DBT_DEVTYP_OEM 0x00000000
    OEM- or IHV-defined device type. This structure is a DEV_BROADCAST_OEM structure.
    DBT_DEVTYP_PORT 0x00000003
    Port device (serial or parallel). This structure is a DEV_BROADCAST_PORT structure.
    DBT_DEVTYP_VOLUME 0x00000002
    Logical volume. This structure is a DEV_BROADCAST_VOLUME structure.
dbch_reserved:
    Reserved; do not use.
*/
LRESULT CALLBACK _usbDetectorCallback(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PDEV_BROADCAST_DEVICEINTERFACE pDevInf;

    if (message != WM_DEVICECHANGE)
        return DefWindowProc(hwnd, message, wParam, lParam);

    DEV_BROADCAST_HDR *lpdb = (DEV_BROADCAST_HDR *) lParam;
    if (lpdb && lpdb->dbch_devicetype == DBT_DEVTYP_VOLUME)
        return DefWindowProc(hwnd, message, wParam, lParam);

    qDebug("wParam = 0x%x", wParam);
    switch (wParam) {
    case DBT_DEVNODES_CHANGED:
        qDebug("DBT_DEVNODES_CHANGED message received, no extended info.");
        break;
    // device add
    case DBT_DEVICEARRIVAL:
    // device remove
    case DBT_DEVICEREMOVECOMPLETE:
        if (lpdb->dbch_devicetype != DBT_DEVTYP_DEVICEINTERFACE)
            break;

        pDevInf = (PDEV_BROADCAST_DEVICEINTERFACE)lpdb;
        UpdateDevice(pDevInf, wParam);
        break;
    default:
        qWarning("WM_DEVICECHANGE message received, unhandled value %d.", wParam);
        break;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}

void UsbDetector::usbDetectorCallback()
{

}

bool UsbDetector::startDetector()
{
    if (!init())
        return false;

    if (!mHWND) {
        stopDetector();
    }

    return true;
}

bool UsbDetector::stopDetector()
{
    UnregisterDeviceNotification(mDevNotify);
    return true;
}

bool UsbDetector::init()
{
    DEV_BROADCAST_DEVICEINTERFACE NotificationFilter;

    mHWND = CreateWindow(L"Button",
                         L"xcmd" , WS_POPUP,
                         0, 0,
                         20, 30,
                         NULL,
                         0, NULL, GetModuleHandle(NULL));
    SetWindowLongA(mHWND, GWL_WNDPROC, (LONG)_usbDetectorCallback);
    //usb volume
    GUID interfaceGUID={0xA5DCBF10, 0x6530, 0x11D2,
                        {0x90, 0x1F, 0x00, 0xC0, 0x4F, 0xB9, 0x51, 0xED}};
    ZeroMemory(&NotificationFilter, sizeof(NotificationFilter));

    NotificationFilter.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
    NotificationFilter.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
    NotificationFilter.dbcc_classguid = interfaceGUID;

    mDevNotify = RegisterDeviceNotification(mHWND,
                    &NotificationFilter, DEVICE_NOTIFY_WINDOW_HANDLE);

    return true;
}
