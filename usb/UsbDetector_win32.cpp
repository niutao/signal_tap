#include "UsbDetector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <linux/netlink.h>
#include <errno.h>
#include <unistd.h>

#include <QtCore>

#define UEVENT_BUFFER_SIZE      2048

enum udev_monitor_netlink_group {
    UDEV_MONITOR_NONE,
    UDEV_MONITOR_KERNEL,
    UDEV_MONITOR_UDEV
};
UsbDetector::UsbDetector(QObject * parent):
QObject(parent)
{
    mNetLinkSocket = -1;
    mSocketNotifier = NULL;
}

UsbDetector::~UsbDetector()
{
    stopDetector();
    close(mNetLinkSocket);
    mNetLinkSocket = -1;
}

bool UsbDetector::startDetector()
{
    if (!init())
        return false;

    mSocketNotifier->setEnabled(true);

    return true;
}

bool UsbDetector::stopDetector()
{
    if (mNetLinkSocket != -1) {

        mSocketNotifier->setEnabled(false);

        close(mNetLinkSocket);
        mNetLinkSocket = -1;
    }
    return true;
}

void UsbDetector::parseDeviceInfo()
{
    QByteArray data;

    data.resize(UEVENT_BUFFER_SIZE * 2);
    data.fill(0);
    size_t len = read(mSocketNotifier->socket(), data.data(), UEVENT_BUFFER_SIZE * 2);
    qDebug("read fro socket %d bytes", len);
    data.resize(len);

    //In the original line each information is seperated by 0
    data = data.replace(0, '\n').trimmed();

    if (mSocketBuffer.isOpen())
        mSocketBuffer.close();

    mSocketBuffer.setBuffer(&data);
    mSocketBuffer.open(QIODevice::ReadOnly);

    while (!mSocketBuffer.atEnd()) {
        parseLine(mSocketBuffer.readLine().trimmed());
    }

    mSocketBuffer.close();
}

void UsbDetector::parseLine(const QByteArray & line)
{
    qDebug("%s", line.constData());

    if (!line.contains("/block/"))    //hotplug
        return;

    QString action_str = line.left(line.indexOf('@')).toLower();
    QString dev = "/dev/" + line.right(line.length() - line.lastIndexOf('/') - 1);

    if (action_str == QLatin1String("add")) {
        deviceAdded(dev);
    } else if (action_str == QLatin1String("remove")) {
        deviceRemoved(dev);
    } else if (action_str == QLatin1String("change")) {
        deviceChanged(dev);
    }

    qDebug("NIUTAOACTION = %s\n", qPrintable(action_str));
    qDebug("NIUTAODEV = %s\n", qPrintable(dev));
}

/******************************************************************************
    UsbDetector: watching depends on platform
    Copyright (C) 2011 Wang Bin <wbsecg1@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
******************************************************************************/

#include <QtCore/QStringList>
#include <QtCore/QCoreApplication>

#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#include <dbt.h>

#ifndef DBT_CUSTOMEVENT
#define DBT_CUSTOMEVENT 0x8006
#endif

static HDEVNOTIFY hDevNotify = 0;
static const GUID GUID_DEVINTERFACE_USBSTOR =
    { 0xA5DCBF10L, 0x6530, 0x11D2, {0x90, 0x1F, 0x00, 0xC0, 0x4F, 0xB9, 0x51, 0xED} };
static const GUID InterfaceClassGuid = GUID_DEVINTERFACE_USBSTOR;

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
    if (message == WM_DEVICECHANGE) {
        DEV_BROADCAST_HDR *lpdb = (DEV_BROADCAST_HDR *) lParam;
        zDebug("Device type address: %#x", lpdb);
        if (lpdb) {
            if (lpdb->dbch_devicetype == DBT_DEVTYP_VOLUME) {
                zDebug("DBT_DEVTYP_VOLUME");
            } else if (lpdb->dbch_devicetype == DBT_DEVTYP_PORT) {
                zDebug("DBT_DEVTYP_PORT");
            } else if (lpdb->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE) {
                zDebug("DBT_DEVTYP_DEVICEINTERFACE");
            } else if (lpdb->dbch_devicetype == DBT_DEVTYP_OEM) {
                zDebug("DBT_DEVTYP_OEM");
            } else {
                zDebug("Unknow device type");
            }
        }

        switch (wParam) {
        case DBT_DEVNODES_CHANGED:
            zDebug("DBT_DEVNODES_CHANGED message received, no extended info.");
            break;
        case DBT_QUERYCHANGECONFIG:
            zDebug("DBT_QUERYCHANGECONFIG message received, no extended info.");
            break;
        case DBT_CONFIGCHANGED:
            zDebug("DBT_CONFIGCHANGED message received, no extended info.");
            break;
        case DBT_CONFIGCHANGECANCELED:
            zDebug("DBT_CONFIGCHANGECANCELED message received, no extended info.");
            break;

        case DBT_DEVICEARRIVAL:
            zDebug("%s\n", lpdb + sizeof(DEV_BROADCAST_HDR));
        case DBT_DEVICEQUERYREMOVE:
        case DBT_DEVICEQUERYREMOVEFAILED:
        case DBT_DEVICEREMOVEPENDING:
        case DBT_DEVICEREMOVECOMPLETE:
            zDebug("wParam = 0x%x\n", wParam);
            if (lpdb->dbch_devicetype == DBT_DEVTYP_PORT) {
                zDebug("DBT_DEVTYP_PORT");
                PDEV_BROADCAST_PORT pDevPort = (PDEV_BROADCAST_PORT) lpdb;
            } else if (lpdb->dbch_devicetype == DBT_DEVTYP_DEVICEINTERFACE) {
                //RegisterDeviceNotification()
                zDebug("DBT_DEVTYP_DEVICEINTERFACE");
                PDEV_BROADCAST_DEVICEINTERFACE pDevInf = (PDEV_BROADCAST_DEVICEINTERFACE) lpdb;
                wchar_t devname[128];
                lstrcpy(devname, pDevInf->dbcc_name);
                for (int i = 0; i < 128; i++) {
                    if (devname[i] == 0)
                        break;
                    printf("%c", devname[i]);
                }
                zDebug("\n");
                UpdateDevice(pDevInf, wParam);
            } else if (lpdb->dbch_devicetype == DBT_DEVTYP_OEM) {
                zDebug("DBT_DEVTYP_OEM");
                DEV_BROADCAST_OEM *pDevOem = (DEV_BROADCAST_OEM *) lpdb;
            } else if (lpdb->dbch_devicetype == DBT_DEVTYP_HANDLE) {
                zDebug("DBT_DEVTYP_HANDLE");
                PDEV_BROADCAST_HANDLE pDevHnd = (PDEV_BROADCAST_HANDLE) lpdb;
            } else {
                zDebug("wParam = 0x%x\n", wParam);
            }
            break;
        case DBT_DEVICETYPESPECIFIC:
            zDebug("DBT_DEVICETYPESPECIFIC message received, may contain an extended info.");
            break;
        case DBT_CUSTOMEVENT:
            zDebug("DBT_CUSTOMEVENT message received, contains an extended info.");
            break;
        case DBT_USERDEFINED:
            zDebug("WM_DEVICECHANGE user defined message received, can not handle.");
            break;
        default:
            qWarning("WM_DEVICECHANGE message received, unhandled value %d.", wParam);
            break;
        }
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}

static inline QString className()
{
    return QLatin1String("UsbDetectorWin32_Internal_Widget") +
        QString::number(quintptr(dw_internal_proc));
}

UsbDetector::~UsbDetector()
{
    stop();
}
void UsbDetector::usbDetectorCallback()
{

}

bool UsbDetector::startDetector()
{
    if (!init())
        return false;

    if (!hwnd) {
        stopDetector();
    }
}

bool UsbDetector::stopDetector()
{
    UnregisterDeviceNotification(hDevNotify);
    UnregisterClass(reinterpret_cast < const wchar_t * >(className().utf16()),
                    qWinAppInst());
    return true;
}

bool UsbDetector::init()
{
    QString className =::className();
    HINSTANCE hi = qWinAppInst();

    WNDCLASS wc;
    wc.style = 0;
    wc.lpfnWndProc = _usbDetectorCallback;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hi;
    wc.hIcon = 0;
    wc.hCursor = 0;
    wc.hbrBackground = 0;
    wc.lpszMenuName = NULL;
    wc.lpszClassName = reinterpret_cast < const wchar_t *>(className.utf16());
    RegisterClass(&wc);

        DEV_BROADCAST_DEVICEINTERFACE NotificationFilter;
        ZeroMemory(&NotificationFilter, sizeof(NotificationFilter));
        NotificationFilter.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
        NotificationFilter.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
        NotificationFilter.dbcc_classguid = InterfaceClassGuid;
        //3rd param with DEVICE_NOTIFY_ALL_INTERFACE_CLASSES and dbcc_classguid will be ignored
        //http://msdn.microsoft.com/en-us/library/windows/desktop/aa363431(v=vs.85).aspx
        hDevNotify = RegisterDeviceNotification(hwnd, &NotificationFilter, DEVICE_NOTIFY_WINDOW_HANDLE);
        if (!hDevNotify) {
            zDebug("");
        }
        SetWindowLong(hwnd, GWL_USERDATA, (LONG) this);
    return true;
}
