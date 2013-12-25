#include "UsbManager.h"

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
    qDebug("idVendor = 0x%x, idProduct=0x%x", idVendor, idProduct);

    foreach (UsbDeviceInfo *device, mUsbDevieList) {
        if (device->mIdVendor == idVendor) {

        }
    }
    UsbDeviceInfo *usb = new UsbDeviceInfo();

}

bool UsbManager::startUsbManager()
{
    mUsbDetector->startDetector();
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
