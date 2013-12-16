#include "SignalTap.h"
#include <stdio.h>
#include "WaveView.h"
#include "MenuBar.h"
#include "ToolBar.h"
#include "StatusBar.h"
#include "WaveShow.h"
#include <QSizePolicy>

SignalTap::SignalTap(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi();
    retranslateUi();

    test();
}

SignalTap::~SignalTap()
{
    desetupUi();
}

void SignalTap::setupUi()
{
    // set the default size of window
    resize(800, 600);
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

bool SignalTap::addWaveView()
{
    return true;
}

void SignalTap::test()
{
    WaveView *test;

    test = new WaveView(this);
    mTopTab->addTab(test->mTab, "test");
    mWaveViewList.append(test);

    test = new WaveView(this);
    mTopTab->addTab(test->mTab, "test1");
    mWaveViewList.append(test);
    test->mWaveShow->drawTest();
}
