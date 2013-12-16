#include "MenuCapture.h"
#include "SignalTap.h"
#include "MenuBar.h"

MenuCapture::MenuCapture(MenuBar *parent, SignalTap *st) :
    QMenu(parent)
{
    setupUi();
    retranslateUi();
}

MenuCapture::~MenuCapture()
{
    desetupUi();
}
void MenuCapture::setupUi()
{
    setTitle(QApplication::translate(SIGNALTAP_CONTEXT, "&Capture", 0));

    actionCaptureStart = new QAction(this);
    actionCaptureStop = new QAction(this);
    actionCaptureStartWithTime = new QAction(this);
    actionCaptureSetup = new QAction(this);
    actionCaptureSampling = new QAction(this);
    actionCaptureTrigger = new QAction(this);

    addAction(actionCaptureStart);
    addAction(actionCaptureStop);
    addAction(actionCaptureStartWithTime);
    addSeparator();
    addAction(actionCaptureSetup);
    addAction(actionCaptureSampling);
    addAction(actionCaptureTrigger);

}
void MenuCapture::retranslateUi()
{
    actionCaptureStart->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Start", 0));
    actionCaptureStop->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Stop", 0));
    actionCaptureStartWithTime->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Start With Time...", 0));
    actionCaptureSetup->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Setup...", 0));
    actionCaptureSampling->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Sampling...", 0));
    actionCaptureTrigger->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Trigger...", 0));
}

void MenuCapture::desetupUi()
{
    delete actionCaptureStart;
    delete actionCaptureStop;
    delete actionCaptureStartWithTime;
    delete actionCaptureSetup;
    delete actionCaptureSampling;
    delete actionCaptureTrigger;
}
