#include "SignalTap.h"
#include "MenuBar.h"
#include "MenuFile.h"
#include "MenuEdit.h"
#include "MenuView.h"
#include "MenuCapture.h"
#include "MenuReplay.h"
#include "MenuHelp.h"

MenuBar::MenuBar(SignalTap *st):
    QMenuBar(st)
{
    this->st = st;
    setupUi();
    retranslateUi();
}
MenuBar::~MenuBar()
{
    desetupUi();
}

void MenuBar::setupUi()
{
    mMenuFile = new MenuFile(this, st);
    mMenuEdit = new MenuEdit(this, st);
    mMenuView = new MenuView(this, st);
    mMenuCapture = new MenuCapture(this, st);
    mMenuReplay = new MenuReplay(this, st);
    mMenuHelp = new MenuHelp(this, st);

    addAction(mMenuFile->menuAction());
    addAction(mMenuEdit->menuAction());
    addAction(mMenuView->menuAction());
    addAction(mMenuCapture->menuAction());
    addAction(mMenuReplay->menuAction());
    addAction(mMenuHelp->menuAction());
}

void MenuBar::desetupUi()
{
    delete mMenuFile;
    delete mMenuEdit;
    delete mMenuView;
    delete mMenuCapture;
    delete mMenuReplay;
    delete mMenuHelp;
}

void MenuBar::retranslateUi()
{
}
