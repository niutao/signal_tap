#include "MenuReplay.h"
#include "SignalTap.h"
#include "MenuBar.h"

MenuReplay::MenuReplay(MenuBar *parent, SignalTap *st) :
    QMenu(parent)
{
    setupUi();
    retranslateUi();
}

MenuReplay::~MenuReplay()
{
    desetupUi();
}
void MenuReplay::setupUi()
{
    setTitle(QApplication::translate(SIGNALTAP_CONTEXT, "&Replay", 0));

    actionReplayReplay = new QAction(this);
    actionReplayReplayFromFile = new QAction(this);

    addAction(actionReplayReplay);
    addAction(actionReplayReplayFromFile);
}
void MenuReplay::retranslateUi()
{
    actionReplayReplay->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Replay", 0));
#ifndef QT_NO_TOOLTIP
    actionReplayReplay->setToolTip(QApplication::translate(SIGNALTAP_CONTEXT, "Replay current wave", 0));
#endif // QT_NO_TOOLTIP
    actionReplayReplayFromFile->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Replay from file...", 0));
}

void MenuReplay::desetupUi()
{
    delete actionReplayReplay;
    delete actionReplayReplayFromFile;
}
