#include "ToolBar.h"
#include "SignalTap.h"
#include "MenuBar.h"
#include "MenuFile.h"

ToolBar::ToolBar(SignalTap *st):
    QToolBar(st)
{
    mST = st;
    setupUi();
    retranslateUi();
}

ToolBar::~ToolBar()
{
    desetupUi();
}

void ToolBar::setupUi()
{
    QIcon icon;

    // set the height and width of toolbar, and the size of icon in
    // toolbar
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    setSizePolicy(sizePolicy);
    setMaximumSize(QSize(16777215, 32));
    setIconSize(QSize(20, 20));
#if 0
    mNew = new QAction(this);
    icon.addFile(QStringLiteral(":/res/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
    mNew->setIcon(icon);
    mNew->setAutoRepeat(true);
    mNew->setIconVisibleInMenu(true);
#else
    mNew = mST->mMenuBar->mMenuFile->mNew;
#endif
    addAction(mNew);

    // add a space widget to tool bar to make the action after than it
    // can right align on the tool bar
    QWidget *spacer;
    spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    addWidget(spacer);

    // go to the first position of the wave
    mGoBegin = new QAction(this);
    icon.addFile(QStringLiteral(":/res/images/go-first-32.png"), QSize(), QIcon::Normal, QIcon::Off);
    mGoBegin->setIcon(icon);
    mGoBegin->setAutoRepeat(true);
    mGoBegin->setIconVisibleInMenu(true);
    addAction(mGoBegin);

    mGoPrev = new QAction(this);
    icon.addFile(QStringLiteral(":/res/images/go-previous-32.png"), QSize(), QIcon::Normal, QIcon::Off);
    mGoPrev->setIcon(icon);
    mGoPrev->setAutoRepeat(true);
    mGoPrev->setIconVisibleInMenu(true);
    addAction(mGoPrev);

    mGoNext = new QAction(this);
    icon.addFile(QStringLiteral(":/res/images/go-next-32.png"), QSize(), QIcon::Normal, QIcon::Off);
    mGoNext->setIcon(icon);
    mGoNext->setAutoRepeat(true);
    mGoNext->setIconVisibleInMenu(true);
    addAction(mGoNext);

    mGoLast = new QAction(this);
    icon.addFile(QStringLiteral(":/res/images/go-last-32.png"), QSize(), QIcon::Normal, QIcon::Off);
    mGoLast->setIcon(icon);
    mGoLast->setAutoRepeat(true);
    mGoLast->setIconVisibleInMenu(true);
    addAction(mGoLast);
}

void ToolBar::desetupUi()
{
}

void ToolBar::retranslateUi()
{
    mGoBegin->setToolTip(QApplication::translate(SIGNALTAP_CONTEXT, "go to the first page of the wave", 0));
    mGoPrev->setToolTip(QApplication::translate(SIGNALTAP_CONTEXT, "go to the previous page of the wave", 0));
    mGoNext->setToolTip(QApplication::translate(SIGNALTAP_CONTEXT, "go to the next page of the wave", 0));
    mGoLast->setToolTip(QApplication::translate(SIGNALTAP_CONTEXT, "go to the last page of the wave", 0));
}
