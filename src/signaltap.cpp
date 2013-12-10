#include "signaltap.h"
#include "ui_signaltap.h"

SignalTap::SignalTap(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignalTap)
{
    ui->setupUi(this);
}

SignalTap::~SignalTap()
{
    delete ui;
}
