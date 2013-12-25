#ifndef USBMANAGER_H
#define USBMANAGER_H

#include <QObject>
#include "UsbDetector.h"
#include "UsbHandler.h"

class UsbDeviceInfo
{
public:
    explicit UsbDeviceInfo();
    uint16_t mIdVendor;
    uint16_t mIdProduct;
    QString mDevPath;
    QString mProduct;
};

class UsbManager : public QObject
{
    Q_OBJECT
public:
    explicit UsbManager(QObject *parent = 0);
    ~UsbManager();

    bool startUsbManager();
    void stopUsbManager();

private:
    UsbDetector *mUsbDetector;
    QList <UsbDeviceInfo *> mUsbDevieList;
signals:

public slots:
    void deviceChanged(uint16_t idVendor, uint16_t idProduct, QString &action,
                       QString &devpath, QString &other);
};

#endif // USBMANAGER_H
