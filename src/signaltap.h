#ifndef SIGNALTAP_H
#define SIGNALTAP_H

#include <QMainWindow>

namespace Ui {
class SignalTap;
}

class SignalTap : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignalTap(QWidget *parent = 0);
    ~SignalTap();

private:
    Ui::SignalTap *ui;
};

#endif // SIGNALTAP_H
