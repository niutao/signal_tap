#ifndef USBDETECTOR_H
#define USBDETECTOR_H

#include <QObject>
#include <QThread>
#include <QBuffer>
#include <stdint.h>
#if defined(Q_OS_LINUX)
#elif defined(Q_OS_WIN32)
#include <windows.h>
#endif

class UsbDetector : public QObject
{
    Q_OBJECT
public:
    explicit UsbDetector(QObject *parent = 0);
    ~UsbDetector();
    bool startDetector();
    bool stopDetector();
private:
    bool init();
#if defined(Q_OS_LINUX)
    int mNetLinkSocket;
    class QSocketNotifier *mSocketNotifier;
    void parseMessage(QByteArray& message);
#elif defined(Q_OS_WIN32)
    HWND mHWND;
    HDEVNOTIFY mDevNotify;
#else
#error "please add the platform support"
#endif
signals:
    void deviceChanged(uint16_t idVendor, uint16_t idProduct, QString &action,
                       QString &devpath, QString &other);
private slots:
    void usbDetectorCallback();
};

#endif // USBDETECTOR_H
