#ifndef USBDETECTOR_H
#define USBDETECTOR_H

#include <QObject>
#include <QThread>

class UsbDetector : public QThread
{
    Q_OBJECT
public:
    explicit UsbDetector();
    ~UsbDetector();
    void run();
signals:

public slots:

};

#endif // USBDETECTOR_H
