#ifndef USBDETECTOR_H
#define USBDETECTOR_H

#include <QObject>
#include <QThread>

class UsbDetector : public QObject, public QThread
{
    Q_OBJECT
public:
    explicit UsbDetector(QObject *parent = 0);
    ~UsbDetector();
    void run();
signals:

public slots:

};

#endif // USBDETECTOR_H
