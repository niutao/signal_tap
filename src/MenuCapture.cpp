#include "MenuCapture.h"
#include "SignalTap.h"
#include "MenuBar.h"
#include "WaveView.h"

MenuCapture::MenuCapture(MenuBar *parent) :
    QMenu(parent)
{
    mST = parent->mST;

    setupUi();
    retranslateUi();

    connect(mStart, SIGNAL(triggered()), this, SLOT(onStartTriggered()));
    connect(mStop, SIGNAL(triggered()), this, SLOT(onStopTriggered()));
    connect(mStartWithTime, SIGNAL(triggered()), this, SLOT(onStartWithTimeTriggered()));
    connect(mSetup, SIGNAL(triggered()), this, SLOT(onSetupTriggered()));
    connect(mSampling, SIGNAL(triggered()), this, SLOT(onSamplingTriggered()));
    connect(mTrigger, SIGNAL(triggered()), this, SLOT(onTriggerTriggered()));
}

MenuCapture::~MenuCapture()
{
    desetupUi();
}
void MenuCapture::setupUi()
{
    setTitle(QApplication::translate(SIGNALTAP_CONTEXT, "&Capture", 0));

    mStart = new QAction(this);
    QIcon iconStart;
    iconStart.addFile(QStringLiteral(":/res/images/start_capture.png"),
                    QSize(), QIcon::Normal, QIcon::Off);
    mStart->setIcon(iconStart);
    addAction(mStart);

    mStop = new QAction(this);
    QIcon iconStop;
    iconStop.addFile(QStringLiteral(":/res/images/stop_capture.png"),
                    QSize(), QIcon::Normal, QIcon::Off);
    mStop->setIcon(iconStop);
    addAction(mStop);
    mStop->setEnabled(false);

    mStartWithTime = new QAction(this);
    addAction(mStartWithTime);

    addSeparator();

    mSetup = new QAction(this);
    addAction(mSetup);

    mSampling = new QAction(this);
    addAction(mSampling);

    mTrigger = new QAction(this);
    addAction(mTrigger);

}
void MenuCapture::retranslateUi()
{
    mStart->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Start", 0));
    mStart->setToolTip(QApplication::translate(SIGNALTAP_CONTEXT, "Start to capture the signal", 0));

    mStop->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Stop", 0));
    mStop->setToolTip(QApplication::translate(SIGNALTAP_CONTEXT, "Stop to capture the signal", 0));

    mStartWithTime->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Start With Time...", 0));
    mSetup->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Setup...", 0));
    mSampling->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Sampling...", 0));
    mTrigger->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Trigger...", 0));
}

void MenuCapture::desetupUi()
{
    delete mStart;
    delete mStop;
    delete mStartWithTime;
    delete mSetup;
    delete mSampling;
    delete mTrigger;
}

void MenuCapture::onStartTriggered()
{
    WaveView *waveview;

    waveview = mST->getCurrentWaveView();

    if (waveview == NULL)
        waveview = mST->addWaveView();


}


void MenuCapture::onStopTriggered()
{
}


void MenuCapture::onStartWithTimeTriggered()
{
}


void MenuCapture::onSetupTriggered()
{
}


void MenuCapture::onSamplingTriggered()
{
}


void MenuCapture::onTriggerTriggered()
{
}

