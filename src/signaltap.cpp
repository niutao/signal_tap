#include "signaltap.h"
#include <stdio.h>
#include "GraphicsView.h"

SignalTap::SignalTap(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignalTap)
{
    ui->setupUi(this);
    GraphicsView *waveView;
    //showMaximized();
    waveView = new GraphicsView();
    waveView->setObjectName(QStringLiteral("waveView"));
    waveView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //waveView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QBrush brush(QColor(0, 0, 0, 255));
    brush.setStyle(Qt::NoBrush);
    waveView->setBackgroundBrush(brush);

    ui->horizontalLayout->addWidget(waveView);

    mMenuFile = new MenuFile(this);
    mWaveView = new WaveView(waveView);

    mWaveView->drawTest();
}

SignalTap::~SignalTap()
{
    delete mWaveView;
    delete mMenuFile;
    delete ui;
}
