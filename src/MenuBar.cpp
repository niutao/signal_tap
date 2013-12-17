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
    mST = st;
    setupUi();
    retranslateUi();
}
MenuBar::~MenuBar()
{
    desetupUi();
}

void MenuBar::setupUi()
{
    mMenuFile = new MenuFile(this, mST);
    mMenuEdit = new MenuEdit(this, mST);
    mMenuView = new MenuView(this, mST);
    mMenuCapture = new MenuCapture(this, mST);
    mMenuReplay = new MenuReplay(this, mST);
    mMenuHelp = new MenuHelp(this, mST);

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
