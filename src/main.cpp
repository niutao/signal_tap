#include "SignalTap.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget *pDesk = QApplication::desktop();
    SignalTap w(pDesk);

    w.move((pDesk->width() - w.width()) / 2,
           (pDesk->height() - w.height()) / 2);

    w.show();

    return a.exec();
}
