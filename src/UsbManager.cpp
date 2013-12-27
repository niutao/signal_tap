#include "UsbManager.h"
#include <QFile>
#include <QTextStream>
#include "SignalTap.h"
#include "UsbDetector.h"
#include "UsbHandler.h"

UsbManager::UsbManager(QObject *parent) :
    QObject(parent)
{
    mUsbDetector = new UsbDetector(this);

    mUsbDevieList.clear();

    connect(mUsbDetector, SIGNAL(deviceChanged(uint16_t,uint16_t,QString&,QString&,QString&)),
            this, SLOT(deviceChanged(uint16_t,uint16_t,QString&,QString&,QString&)));
}
UsbManager::~UsbManager()
{
    stopUsbManager();
    delete mUsbDetector;
}

void UsbManager::deviceChanged(uint16_t idVendor, uint16_t idProduct,
                               QString &action, QString &devpath, QString &other)
{
    UsbDeviceInfo *found = NULL;

    if (idVendor != SAS_DEVICE_VENDOR || idProduct != SAS_DEVICE_PRODUCT)
        return;

    QFile manufacturer("/sys" + devpath + "/manufacturer");
    if (manufacturer.open(QIODevice::ReadOnly)) {
        QTextStream in(&manufacturer);
        QString data = in.readAll();
        manufacturer.close();
        // we just care our device, if not, ignore this device
        if (!data.startsWith(SIGNALTAP_DEVICE_MANUFACTURER))
            return;
    }

    foreach (UsbDeviceInfo *device, mUsbDevieList) {
        if (device->mIdVendor == idVendor &&
                device->mIdProduct == idProduct &&
                device->mDevPath.compare(devpath) == 0) {
            found = device;
        }
    }

    // there is a new device has been found, add it to list
    if (action.compare("add") == 0 && !found) {
        UsbDeviceInfo *usb = new UsbDeviceInfo();
        usb->init(idVendor, idProduct, devpath, other);
        mUsbDevieList.append(usb);
        emit deviceAdded(usb);
    } else if (action.compare("remove") == 0 && found) {
        emit deviceRemoved(found);
        delete found;
    }
}

UsbDeviceInfo *UsbManager::findDevice(QString name)
{
    foreach (UsbDeviceInfo *device, mUsbDevieList) {
        if (name.compare(device->mName) == 0)
            return device;
    }

    return NULL;
}

bool UsbManager::startUsbManager()
{
    int ret;
    ret = mUsbDetector->startDetector();
    mUsbDetector->scanDevices(SAS_DEVICE_VENDOR, SAS_DEVICE_PRODUCT);
    return ret ? false : true;
}

void UsbManager::stopUsbManager()
{
    mUsbDetector->stopDetector();
}
UsbDeviceInfo::UsbDeviceInfo()
{
    mIdVendor = 0;
    mIdProduct = 0;
}

void UsbDeviceInfo::init(uint16_t idVendor, uint16_t idProduct,
                         QString &devpath, QString &other)
{
    mIdVendor = idVendor;
    mIdProduct = idProduct;
    mDevPath = devpath;
    mProduct = other;
    mName = QString(SIGNALTAP_DEVICE_MANUFACTURER) + " " +
            devpath.mid(devpath.lastIndexOf("/", -1) + 1);
}
