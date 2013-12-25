#ifndef USBDETECTOR_H
#define USBDETECTOR_H

#include <QObject>
#include <QThread>
#include <QBuffer>
#include <stdint.h>

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
    int mNetLinkSocket;
#ifdef Q_OS_LINUX
    class QSocketNotifier *mSocketNotifier;
    void parseMessage(QByteArray& message);
#elif Q_OS_WIN32
    HWND hwnd;
#else
#error "please add the platform support"
#endif
signals:
    void deviceChanged(uint16_t idVendor, uint16_t idProduct, QString &action,
                       QString &devpath, QString &other);
public slots:
    void usbDetectorCallback();
};

#endif // USBDETECTOR_H
