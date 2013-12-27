#ifndef USBHANDLER_H
#define USBHANDLER_H

#include <QObject>
#include <QThread>
#include <QString>
#include <stdint.h>
#include "st_usb.h"
/** start to capture the signal */
#define ST_CMD_START_CAP    0xD2
/** stop to capture the signal */
#define ST_CMD_STOP_CAP     0xD3
/** start to output the signal */
#define ST_CMD_START_OUT    0xD4
/** stop to output the signal */
#define ST_CMD_STOP_OUT     0xD5

class UsbHandler : public QThread
{
    Q_OBJECT
public:
    explicit UsbHandler(QObject *parent = 0);
    explicit UsbHandler(uint16_t idVendor, uint16_t idProduct, int sampleRate);
    ~UsbHandler();
    void run();

    /**
     * @brief State the state machine of usb port
     */
    enum State {
        //! the usb port has been closed
        CLOSED,
        //! the usb port is opened
        OPENED,
        //! there is a progress readding data from usb port
        READING,
        STOPREADING,
        //! there is a progress writing data to usb port
        WRITING,
        STOPWRITING,
    };
private:
    //! the handler of usb device
    struct st_usb *mDevice;

    //! the sampling rate of read or write the FPGA port
    //! the base unit of mSampleRate is nanosecond, ie
    //! mSampleRate=10 means the sampling rate is 10 nanosecond,
    //! so the sampling period is 100MHz
    int mSampleRate;
    //! the state of handler, see @State
    State mState;
    //! the total time of reading the data from usb port, or
    //! writing the data to usb port
    int mTotalTime;
#define USBHANDLEER_INVALID_TIME -1
    //! the used time of handle the usb port
    int mUsedTime;

    uint16_t mIdVendor;
    uint16_t mIdProduct;
    QString mSavedName;
    int mReadEndPoint;
    int mWriteEndPoint;
public:
    //! get hte used time
    int getUsedTime() { return mUsedTime; }
    void setState(State state) { mState = state; }
    void setSavedName(QString *name) {mSavedName = *name; }
    void setReadEndPoint(int endpoint) { mReadEndPoint = endpoint; }
    void setWriteEndPoint(int endpoint) { mWriteEndPoint = endpoint; }
    /**
     * @brief openDevice
     *        open the usb device
     *
     * @return
     * return 0 if success, otherwise return a negative error
     * code, see <errno.h>
     */
    int openDevice();
    int openDevice(uint16_t idVendor, uint16_t idProduct);

    int closeDevice();

    /**
     * @brief sendCtlMsg send the control message to usb device
     * @param request USB message request value
     * @param value USB message value
     * @param data pointer to the data to send
     * @param size length in bytes of the data to send
     * @param timeout time in msecs to wait for the message to
     * complete before timing out (if 0 the wait is forever)
     * @return return 0 if success, otherwise return negative number, see <errno.h>
     *
     * @note this function maybe blocked until timeout
     */
    int sendCtlMsg(int request, int value, char *data, int size, int timeout);
    int readRawData(int endpoint, char *data, int size, int timeout);
    int writeRawData(int endpoint, char *data, int size, int timeout);
signals:
    void dataValid();
    void deviceInValid();
    void dataError();
    void errorFound(int error);
    void dataSaved();
public slots:

};

#endif // USBHANDLER_H
