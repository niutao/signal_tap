#ifndef SIGNALTAP_H
#define SIGNALTAP_H

#include <QMainWindow>
#include "MenuFile.h"
#include "ui_signaltap.h"
#include "WaveView.h"

namespace Ui {
class SignalTap;
}


class SignalTap : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignalTap(QWidget *parent = 0);
    ~SignalTap();

public:
    Ui::SignalTap *ui;
    MenuFile *mMenuFile;
    WaveView *mWaveView;

};

#endif // SIGNALTAP_H
