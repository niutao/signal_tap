#ifndef USBDETECTOR_H
#define USBDETECTOR_H

#include <QObject>
#include <QThread>
#include <QBuffer>
#ifdef Q_OS_WIN
#include <qt_windows.h>
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
    QBuffer mSocketBuffer;
    int mNetLinkSocket;
    class QSocketNotifier *mSocketNotifier;
    void parseLine(const QByteArray& line);
#elif defined(Q_OS_WIN32)
    HWND mHWND;
    HDEVNOTIFY mDevNotify;
#else
#error "please add the platform support"
#endif
signals:
    void deviceAdded(const QString& dev);
    void deviceChanged(const QString& dev);
    void deviceRemoved(const QString& dev);
public slots:
    void usbDetectorCallback();
};

#endif // USBDETECTOR_H
