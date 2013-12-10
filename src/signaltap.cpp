#include "signaltap.h"
#include "ui_signaltap.h"
#include "MenuFile.h"
#include <stdio.h>

SignalTap::SignalTap(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignalTap)
{
    ui->setupUi(this);
    menuFile = new MenuFile(this);

}

SignalTap::~SignalTap()
{
    delete ui;
}
