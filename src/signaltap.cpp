#include "signaltap.h"
#include <stdio.h>
#include "GraphicsView.h"
#include "WaveView.h"

SignalTap::SignalTap(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignalTap)
{
    ui->setupUi(this);

    mMenuFile = new MenuFile(this);
    mWaveView = new WaveView(parent);

    ui->horizontalLayout->addWidget(mWaveView->mGraphicsView);
    mWaveView->drawTest();
}

SignalTap::~SignalTap()
{
    delete mWaveView;
    delete mMenuFile;
    delete ui;
}
