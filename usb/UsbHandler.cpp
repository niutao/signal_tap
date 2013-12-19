#include "UsbHandler.h"
#include "st_usb.h"
#include <errno.h>

UsbHandler::UsbHandler(QObject *parent) :
    QObject(parent)
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

    if (mState == CLOSED)
        return -EPIPE;

    mState = READING;
    ret = st_usb_bulk_read(mDevice, endpoint, data, size, timeout);
    mState = OPENED;

    return ret;
}

int UsbHandler::writeRawData(int endpoint, char *data, int size, int timeout)
{
    int ret;

    if (mState == CLOSED)
        return -EPIPE;

    mState = WRITING;
    ret = st_usb_bulk_write(mDevice, endpoint, data, size, timeout);
    mState = OPENED;

    return ret;
}
