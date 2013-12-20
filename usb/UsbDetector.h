#ifndef USBDETECTOR_H
#define USBDETECTOR_H

#include <QObject>
#include <QThread>
#include <QBuffer>

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
    QBuffer mSocketBuffer;
    class QSocketNotifier *mSocketNotifier;
    void parseLine(const QByteArray& line);
#elif Q_OS_WIN32
    HWND hwnd;
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
