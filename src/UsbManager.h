#ifndef USBMANAGER_H
#define USBMANAGER_H

#include <stdint.h>
#include <QObject>

#define SAS_DEVICE_VENDOR 0x04b4
#define SAS_DEVICE_PRODUCT 0x4001

class UsbDetector;
class UsbHandler;

class UsbDeviceInfo
{
public:
    explicit UsbDeviceInfo();
    void init(uint16_t idVendor, uint16_t idProduct,
                             QString &devpath, QString &other);
    uint16_t mIdVendor;
    uint16_t mIdProduct;
    QString mDevPath;
    QString mProduct;
    QString mName;
};

class UsbManager : public QObject
{
    Q_OBJECT
public:
    explicit UsbManager(QObject *parent = 0);
    ~UsbManager();

    bool startUsbManager();
    void stopUsbManager();
    UsbDeviceInfo *findDevice(QString device);

private:
    UsbDetector *mUsbDetector;
    QList <UsbDeviceInfo *> mUsbDevieList;
public:
    QList <UsbDeviceInfo *> & getDeviceList() { return mUsbDevieList; }
signals:
    void deviceAdded(UsbDeviceInfo *device);
    void deviceRemoved(UsbDeviceInfo *device);
public slots:
    void deviceChanged(uint16_t idVendor, uint16_t idProduct, QString &action,
                       QString &devpath, QString &other);
};

#endif // USBMANAGER_H
