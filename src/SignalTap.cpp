#include "SignalTap.h"
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include "WaveView.h"
#include "MenuBar.h"
#include "ToolBar.h"
#include "StatusBar.h"
#include "WaveShow.h"
#include "WaveTimeLine.h"
#include <QSizePolicy>
#include <QPushButton>

SignalTap::SignalTap(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi();
    retranslateUi();
}

SignalTap::~SignalTap()
{
    desetupUi();
}

void SignalTap::setupUi()
{
    // set the default size of window
    resize(800, 600);
    setWindowState(Qt::WindowMaximized);
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    setSizePolicy(sizePolicy1);

    // set the logo of software
    QIcon icon;
    icon.addFile(QStringLiteral(":/res/images/logo.png"),
                 QSize(), QIcon::Normal, QIcon::Off);
    setWindowIcon(icon);

    // create the menu bar
    mMenuBar = new MenuBar(this);
    setMenuBar(mMenuBar);

    // create tool bar
    mToolBar = new ToolBar(this);
    addToolBar(Qt::TopToolBarArea, mToolBar);

    mTopWidget = new QWidget(this);
    QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(mTopWidget->sizePolicy().hasHeightForWidth());
    mTopWidget->setSizePolicy(sizePolicy2);

    // set the top widget as central widget
    setCentralWidget(mTopWidget);

    mTopHL = new QHBoxLayout(mTopWidget);
    mTopHL->setSpacing(6);
    mTopHL->setContentsMargins(11, 11, 11, 11);
    mTopHL->setContentsMargins(0, 0, 0, 0);

    // create the tabl widget
    mTopTab = new QTabWidget(mTopWidget);
    mTopTab->setFocusPolicy(Qt::NoFocus);
    // set the width of tab
    mTopTab->setStyleSheet("QTabBar::tab{width:120;height:32}");

    mTopTab->tabBar()->setElideMode(Qt::ElideRight);
    mTopTab->setDocumentMode(false);
    // set the width of tab bar
    mTopHL->addWidget(mTopTab);

    // create the status bar
    mStatusBar = new StatusBar(this);
    setStatusBar(mStatusBar);

    mWaveViewList.clear();
}

void SignalTap::retranslateUi()
{
    setWindowTitle(QApplication::translate(SIGNALTAP_CONTEXT, "SignalTap", 0));
}

void SignalTap::desetupUi()
{
    delete mStatusBar;
    delete mTopTab;
    delete mTopHL;
    delete mTopWidget;
    delete mToolBar;
    delete mMenuBar;
}
bool SignalTap::removeWaveView(int index)
{
    int count = mTopTab->count();

    if (index < 0 || index >= count)
        return false;

    mTopTab->removeTab(index);
    QWidget *tab = mTopTab->widget(index);

    foreach (WaveView *waveview, mWaveViewList) {
        if (waveview->mTab == tab) {
            mWaveViewList.removeOne(waveview);
            return true;
        }
    }
    return false;
}

bool SignalTap::removeWaveView(WaveView *waveview)
{
    foreach (WaveView *wave, mWaveViewList) {
        if (wave == waveview) {
            int index = mTopTab->indexOf(wave->mTab);
            if (index != -1)
                mTopTab->removeTab(index);
            mWaveViewList.removeOne(wave);
            return index != -1 ? true : false;
        }
    }

    return false;
}

bool SignalTap::addWaveView(QString &wave)
{
    WaveView *waveview;

    if (wave.isEmpty()) {
        QDateTime dt;
        QTime time;
        QDate date;

        dt.setTime(time.currentTime());
        dt.setDate(date.currentDate());
        QString currentDate = dt.toString("yyyyMMdd-hhmmss");
        wave = (QString)"wave-" + currentDate;
    }

    qDebug("%s\n",(const char *) wave.toLocal8Bit());

    waveview = new WaveView(this);

    int index = mTopTab->addTab(waveview->mTab, basename(wave.toLatin1().data()));
    mTopTab->tabBar()->setTabButton(index, QTabBar::RightSide, waveview->mCloseButton);
    mTopTab->setTabToolTip(index, wave);
    mTopTab->setCurrentIndex(index);

    mWaveViewList.append(waveview);

    waveview->openWave(wave);

    return true;
}
bool SignalTap::addWaveView()
{
    QString lable = "";
    addWaveView(lable);
}

