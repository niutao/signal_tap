#include "MenuFile.h"
#include <QDebug>
#include <stdio.h>
#include "SignalTap.h"
#include "MenuBar.h"
#include <QFileDialog>

MenuFile::MenuFile(MenuBar *parent):
    QMenu(parent)
{
    mST = parent->mST;
    setupUi();
    retranslateUi();

    connect(mNew, SIGNAL(triggered()), this, SLOT(onNewTriggered()));
    connect(mOpen, SIGNAL(triggered()), this, SLOT(onOpenTriggered()));
    connect(mSave, SIGNAL(triggered()), this, SLOT(onSaveTriggered()));
    connect(mExportAsBIN, SIGNAL(triggered()), this, SLOT(onExportAsBINTriggered()));
    connect(mExportAsWLF, SIGNAL(triggered()), this, SLOT(onExportAsWLFTriggered()));
    connect(mPrint, SIGNAL(triggered()), this, SLOT(onPrintTriggered()));
    connect(mPrintSetup, SIGNAL(triggered()), this, SLOT(onPrintSetupTriggered()));
    connect(mExit, SIGNAL(triggered()), this, SLOT(onExitTriggered()));

}
MenuFile::~MenuFile()
{
    desetupUi();
}

void MenuFile::setupUi()
{
    setTitle(QApplication::translate(SIGNALTAP_CONTEXT, "&File", 0));

    mNew = new QAction(this);
    QIcon iconNew;
    iconNew.addFile(QStringLiteral(":/res/images/new.png"),
                    QSize(), QIcon::Normal, QIcon::Off);
    mNew->setIcon(iconNew);
    addAction(mNew);

    mOpen = new QAction(this);
    QIcon iconOpen;
    iconOpen.addFile(QStringLiteral(":/res/images/open.png"),
                     QSize(), QIcon::Normal, QIcon::Off);
    mOpen->setIcon(iconOpen);
    addAction(mOpen);

    mSave = new QAction(this);
    addAction(mSave);

    addSeparator();

    mExportAsBIN = new QAction(this);
    addAction(mExportAsBIN);

    mExportAsWLF = new QAction(this);
    addAction(mExportAsWLF);

    addSeparator();

    mPrint = new QAction(this);
    addAction(mPrint);

    mPrintSetup = new QAction(this);
    addAction(mPrintSetup);

    addSeparator();

    mExit = new QAction(this);
    addAction(mExit);
}

void MenuFile::desetupUi()
{
    delete mNew;
    delete mOpen;
    delete mSave;
    delete mExportAsBIN;
    delete mExportAsWLF;
    delete mPrint;
    delete mPrintSetup;
    delete mExit;
}

void MenuFile::retranslateUi()
{
    mNew->setText(QApplication::translate(SIGNALTAP_CONTEXT, "New", 0));
    mOpen->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Open...", 0));
    mSave->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Save", 0));
    mExportAsBIN->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Export as binrary...", 0));
    mExportAsWLF->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Export as WLF file...", 0));
    mPrint->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Print", 0));
    mPrintSetup->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Print Setup...", 0));
    mExit->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Exit", 0));
}

void MenuFile::onNewTriggered()
{
    mST->addWaveView();
}

void MenuFile::onOpenTriggered()
{
    QString fileName;

    QFileDialog *fd = new QFileDialog(mST);
    fd->setNameFilter(tr(SIGNALTAP_WAVEFILE_FILTER));
    fd->setFileMode(QFileDialog::ExistingFile);
    fd->setViewMode(QFileDialog::List);
    if (fd->exec() == QDialog::Accepted) {
        fileName = fd->selectedFiles()[0];

        mST->addWaveView(fileName);
    }
    fd->close();

    qDebug("selectedFile = %s\n", (const char *)fileName.toLocal8Bit());
}

void MenuFile::onSaveTriggered()
{
}

void MenuFile::onExportAsBINTriggered()
{
}

void MenuFile::onExportAsWLFTriggered()
{
}

void MenuFile::onPrintTriggered()
{
}

void MenuFile::onPrintSetupTriggered()
{
}

void MenuFile::onExitTriggered()
{
    mST->close();
}


