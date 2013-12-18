#include "MenuHelp.h"
#include "SignalTap.h"
#include "MenuBar.h"

MenuHelp::MenuHelp(MenuBar *parent) :
    QMenu(parent)
{
    setupUi();
    retranslateUi();
}

MenuHelp::~MenuHelp()
{
    desetupUi();
}
void MenuHelp::setupUi()
{
    setTitle(QApplication::translate(SIGNALTAP_CONTEXT, "&Help", 0));

    actionHelpHelpTopic = new QAction(this);
    actionHelpUpdateCheck = new QAction(this);
    actionHelpAboutthis = new QAction(this);
    actionHelpAboutSignalTap = new QAction(this);

    addAction(actionHelpHelpTopic);
    addAction(actionHelpUpdateCheck);
    addSeparator();
    addAction(actionHelpAboutSignalTap);
    addAction(actionHelpAboutSignalTap);
}
void MenuHelp::retranslateUi()
{
    actionHelpHelpTopic->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Help Topic...", 0));
    actionHelpUpdateCheck->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Update Check...", 0));
    actionHelpAboutSignalTap->setText(QApplication::translate(SIGNALTAP_CONTEXT, "About SignalTap", 0));
}

void MenuHelp::desetupUi()
{
    delete actionHelpHelpTopic;
    delete actionHelpUpdateCheck;
    delete actionHelpAboutSignalTap;
}
