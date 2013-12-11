#include "signaltap.h"
#include <stdio.h>

SignalTap::SignalTap(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignalTap)
{
    //showMaximized();
    ui->setupUi(this);


    mMenuFile = new MenuFile(this);
    mWaveView = new WaveView(ui->waveView);

    mWaveView->drawTest();
}

SignalTap::~SignalTap()
{
    delete mWaveView;
    delete mMenuFile;
    delete ui;
}
