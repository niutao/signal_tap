#include "SignalTap.h"
#include <QApplication>
#include "usb/UsbDetector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDesktopWidget *pDesk = QApplication::desktop();
    SignalTap w(pDesk);

    w.move((pDesk->width() - w.width()) / 2,
           (pDesk->height() - w.height()) / 2);

    w.show();

    UsbDetector *usb = new UsbDetector();

    usb->startDetector();

    a.exec();

    usb->stopDetector();

    return 0;
}
