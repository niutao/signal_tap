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
    // disable the right mouse button events
    setContextMenuPolicy(Qt::PreventContextMenu);

    mMenuFile = new MenuFile(this);
    mMenuEdit = new MenuEdit(this);
    mMenuView = new MenuView(this);
    mMenuCapture = new MenuCapture(this);
    mMenuReplay = new MenuReplay(this);
    mMenuHelp = new MenuHelp(this);

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
