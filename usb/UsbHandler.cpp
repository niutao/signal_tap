#include "UsbHandler.h"
#include "st_usb.h"
#include <errno.h>
#include <QFile>
#include <QTextStream>
#include <QDataStream>

UsbHandler::UsbHandler(QObject *parent) :
    QThread(parent)
{
    mDevice = NULL;
    mSampleRate = 0;
    mState = CLOSED;
    mTotalTime = USBHANDLEER_INVALID_TIME;
    mUsedTime = 0;

    mIdVendor = 0x0;
    mIdProduct = 0x0;
}
UsbHandler::UsbHandler(uint16_t idVendor, uint16_t idProduct,
                       int sampleRate)
{
    mDevice = NULL;
    mSampleRate = sampleRate;
    mState = CLOSED;
    mTotalTime = USBHANDLEER_INVALID_TIME;
    mUsedTime = 0;

    mIdVendor = idVendor;
    mIdProduct = idProduct;
}

UsbHandler::~UsbHandler()
{
    if (mDevice != NULL) {
        free(mDevice);
        mDevice = NULL;
    }
}

int UsbHandler::openDevice()
{
    int ret;

    if (mState != CLOSED)
        return 0;

    if (mIdVendor == 0 && mIdProduct == 0)
        return -EINVAL;

    mDevice = st_usb_init();
    if (mDevice == NULL)
        return -ENOMEM;

    ret = st_usb_find_device(mDevice, mIdVendor, mIdProduct);
    if (ret != 0)
        goto err_not_found;

    ret = st_usb_open(mDevice);
    if (ret != 0)
        goto err_not_found;

    mState = OPENED;

    return ret;

err_not_found:
    st_usb_exit(mDevice);
    return ret;
}

int UsbHandler::openDevice(uint16_t idVendor, uint16_t idProduct)
{
    mIdVendor = idVendor;
    mIdProduct = idProduct;

    return openDevice();
}

int UsbHandler::closeDevice()
{
    if (mState == CLOSED)
        return 0;

    st_usb_exit(mDevice);

    return 0;
}

int UsbHandler::sendCtlMsg(int request, int value,
                           char *data, int size, int timeout)
{
    if (mState == CLOSED)
        return -EPIPE;

    return st_usb_control_msg(mDevice,
                              USB_ENDPOINT_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
                              request,
                              value,
                              data,
                              size,
                              timeout);
}

int UsbHandler::readRawData(int endpoint, char *data, int size, int timeout)
{
    int ret;

    if (mState != READING && mState != STOPREADING)
        return -EPIPE;

    ret = st_usb_bulk_read(mDevice, endpoint, data, size, timeout);

    return ret;
}

int UsbHandler::writeRawData(int endpoint, char *data, int size, int timeout)
{
    int ret;

    if (mState != WRITING && mState != STOPWRITING)
        return -EPIPE;

    ret = st_usb_bulk_write(mDevice, endpoint, data, size, timeout);

    return ret;
}

void UsbHandler::run()
{
    bool datavalid = false;
#define USB_BUFFER_SIZE (512 * 4)
    char buffer[USB_BUFFER_SIZE];
    int ret = 1;

    QFile raw_data("/tmp/" + mSavedName);
    qDebug("RawFileName = %s", qPrintable(raw_data.fileName()));
    qDebug("mReadEndPoint = 0x%x", mReadEndPoint);
    if (!raw_data.open(QIODevice::WriteOnly)) {
        emit errorFound(-ENOENT);
        return;
    }
    QDataStream raw(&raw_data);

    while (ret > 0) {
        switch (mState) {
        case READING:
        case STOPREADING:
            //qDebug("Start read");
            ret = readRawData(mReadEndPoint, buffer, USB_BUFFER_SIZE, USB_CTRL_SET_TIMEOUT);
            //qDebug("Read %d bytes", ret);
            if (ret < 0 && mState == READING) {
                emit dataError();
                continue;
            }

            if (ret == 0 || mState == STOPREADING) {
                emit dataSaved();
                ret = 0;
                continue;
            }

            if (!datavalid) {
                emit dataValid();
                datavalid = true;
            }
            raw.writeRawData(buffer, ret);
            break;
        case WRITING:
        case STOPWRITING:
            break;
        default:
            ret = 0;
            break;
        }
    }

    mState = OPENED;
    qDebug("end usb handler thread");
    raw_data.close();
}
