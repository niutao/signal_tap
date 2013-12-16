#include "MenuFile.h"
#include <QDebug>
#include <stdio.h>
#include "SignalTap.h"
#include "MenuBar.h"

MenuFile::MenuFile(MenuBar *parent, SignalTap *st):
    QMenu(parent)
{
    setupUi();
    retranslateUi();

    connect(actionFileNew, SIGNAL(triggered()), this, SLOT(actionFileNewTriggered()));
    connect(actionFileOpen, SIGNAL(triggered()), this, SLOT(actionFileOpenTriggered()));
    connect(actionFileSave, SIGNAL(triggered()), this, SLOT(actionFileSaveTriggered()));
    connect(actionFileExportAsBIN, SIGNAL(triggered()), this, SLOT(actionFileExportAsBINTriggered()));
    connect(actionFileExportAsWLF, SIGNAL(triggered()), this, SLOT(actionFileExportAsWLFTriggered()));
    connect(actionFilePrint, SIGNAL(triggered()), this, SLOT(actionFilePrintTriggered()));
    connect(actionFilePrintSetup, SIGNAL(triggered()), this, SLOT(actionFilePrintSetupTriggered()));
    connect(actionFileExit, SIGNAL(triggered()), this, SLOT(actionFileExitTriggered()));

}
MenuFile::~MenuFile()
{
    desetupUi();
}

void MenuFile::setupUi()
{
    setTitle(QApplication::translate(SIGNALTAP_CONTEXT, "&File", 0));

    actionFileNew = new QAction(this);
    QIcon icon;
    icon.addFile(QStringLiteral(":/res/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
    actionFileNew->setIcon(icon);

    actionFileOpen = new QAction(this);
    actionFileSave = new QAction(this);
    actionFileExportAsBIN = new QAction(this);
    actionFileExportAsWLF = new QAction(this);
    actionFilePrint = new QAction(this);
    actionFilePrintSetup = new QAction(this);
    actionFileExit = new QAction(this);

    addAction(actionFileNew);
    addAction(actionFileOpen);
    addAction(actionFileSave);
    addSeparator();
    addAction(actionFileExportAsBIN);
    addAction(actionFileExportAsWLF);
    addSeparator();
    addAction(actionFilePrint);
    addAction(actionFilePrintSetup);
    addSeparator();
    addAction(actionFileExit);
}
void MenuFile::desetupUi()
{
    delete actionFileNew;
    delete actionFileOpen;
    delete actionFileSave;
    delete actionFileExportAsBIN;
    delete actionFileExportAsWLF;
    delete actionFilePrint;
    delete actionFilePrintSetup;
    delete actionFileExit;
}

void MenuFile::retranslateUi()
{
    actionFileNew->setText(QApplication::translate(SIGNALTAP_CONTEXT, "New", 0));
    actionFileOpen->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Open...", 0));
    actionFileSave->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Save", 0));
    actionFileExportAsBIN->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Export as binrary...", 0));
    actionFileExportAsWLF->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Export as WLF file...", 0));
    actionFilePrint->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Print", 0));
    actionFilePrintSetup->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Print Setup...", 0));
    actionFileExit->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Exit", 0));
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


