#include "MenuEdit.h"
#include "SignalTap.h"
#include "MenuBar.h"

MenuEdit::MenuEdit(MenuBar *parent, SignalTap *st) :
    QMenu(parent)
{
    setupUi();
    retranslateUi();
}

MenuEdit::~MenuEdit()
{
    desetupUi();
}

void MenuEdit::setupUi()
{
    setTitle(QApplication::translate(SIGNALTAP_CONTEXT, "&Edit", 0));

    actionEditClear = new QAction(this);
    actionEditOptions = new QAction(this);
    actionEditZoomIn = new QAction(this);
    actionEditZoomOut = new QAction(this);

    addAction(actionEditZoomIn);
    addAction(actionEditZoomOut);
    addAction(actionEditClear);
    addSeparator();
    addAction(actionEditOptions);

}
void MenuEdit::retranslateUi()
{
    actionEditClear->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Clear", 0));
    actionEditOptions->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Options...", 0));
    actionEditZoomIn->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Zoom In", 0));
    actionEditZoomOut->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Zoom Out", 0));
}

void MenuEdit::desetupUi()
{
    delete actionEditClear;
    delete actionEditOptions;
    delete actionEditZoomIn;
    delete actionEditZoomOut;
}
