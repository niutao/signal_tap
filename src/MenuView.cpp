#include "MenuView.h"
#include "SignalTap.h"
#include "MenuBar.h"

MenuView::MenuView(MenuBar *parent) :
    QMenu(parent)
{
    setupUi();
    retranslateUi();
}

MenuView::~MenuView()
{
    desetupUi();
}
void MenuView::setupUi()
{
    setTitle(QApplication::translate(SIGNALTAP_CONTEXT, "&View", 0));

    actionViewToolBar = new QAction(this);
    actionViewToolBar->setCheckable(true);

    actionViewStatusBar = new QAction(this);
    actionViewStatusBar->setCheckable(true);

    actionViewAutoMensure = new QAction(this);
    actionViewAutoMensure->setCheckable(true);

    addAction(actionViewToolBar);
    addAction(actionViewStatusBar);
    addAction(actionViewAutoMensure);
}
void MenuView::retranslateUi()
{
    actionViewToolBar->setText(QApplication::translate(SIGNALTAP_CONTEXT, "ToolBar", 0));
    actionViewStatusBar->setText(QApplication::translate(SIGNALTAP_CONTEXT, "StatusBar", 0));
    actionViewAutoMensure->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Auto Measure Window", 0));
}

void MenuView::desetupUi()
{
    delete actionViewToolBar;
    delete actionViewStatusBar;
    delete actionViewAutoMensure;
}
