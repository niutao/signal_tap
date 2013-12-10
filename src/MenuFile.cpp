#include "MenuFile.h"
#include <QDebug>
#include <stdio.h>
#include "signaltap.h"
#include "ui_signaltap.h"

MenuFile::MenuFile(SignalTap *st):
    QObject(st)
{
    Ui::SignalTap *ui = st->ui;

    connect(ui->actionFileNew, SIGNAL(triggered()), this, SLOT(actionFileNewTriggered()));
    connect(ui->actionFileOpen, SIGNAL(triggered()), this, SLOT(actionFileOpenTriggered()));
    connect(ui->actionFileSave, SIGNAL(triggered()), this, SLOT(actionFileSaveTriggered()));
    connect(ui->actionFileExportAsBIN, SIGNAL(triggered()), this, SLOT(actionFileExportAsBINTriggered()));
    connect(ui->actionFileExportAsWLF, SIGNAL(triggered()), this, SLOT(actionFileExportAsWLFTriggered()));
    connect(ui->actionFilePrint, SIGNAL(triggered()), this, SLOT(actionFilePrintTriggered()));
    connect(ui->actionFilePrintSetup, SIGNAL(triggered()), this, SLOT(actionFilePrintSetupTriggered()));
    connect(ui->actionFileExit, SIGNAL(triggered()), this, SLOT(actionFileExitTriggered()));

}

void MenuFile::actionFileNewTriggered()
{
}

void MenuFile::actionFileOpenTriggered()
{
}

void MenuFile::actionFileSaveTriggered()
{
}

void MenuFile::actionFileExportAsBINTriggered()
{
}

void MenuFile::actionFileExportAsWLFTriggered()
{
}

void MenuFile::actionFilePrintTriggered()
{
}

void MenuFile::actionFilePrintSetupTriggered()
{
}

void MenuFile::actionFileExitTriggered()
{
}


