#include "ToolBar.h"
#include "SignalTap.h"
#include "MenuBar.h"
#include "MenuFile.h"
#include "MenuCapture.h"

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
    // fix the toolbar on the window
    setMovable(false);
    setFloatable(false);
    // disable the right mouse button events
    setContextMenuPolicy(Qt::PreventContextMenu);
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
    QIcon iconNew;
    iconNew.addFile(QStringLiteral(":/res/images/new.png"),
                 QSize(), QIcon::Normal, QIcon::Off);
    mNew->setIcon(iconNew);
    mNew->setAutoRepeat(true);
    mNew->setIconVisibleInMenu(true);
#else
    // we share the mNew QAction with MenuFile
    mNew = mST->mMenuBar->mMenuFile->mNew;
#endif
    addAction(mNew);

#if 0
    mOpen = new QAction(this);
    QIcon iconOpen;
    iconOpen.addFile(QStringLiteral(":/res/images/open.png"),
                 QSize(), QIcon::Normal, QIcon::Off);
    mOpen->setIcon(iconOpen);
    mOpen->setAutoRepeat(true);
    mOpen->setIconVisibleInMenu(true);
#else
    // we share the mOpen QAction with MenuFile
    mOpen = mST->mMenuBar->mMenuFile->mOpen;
#endif
    addAction(mOpen);

#if 0
    mStartCapture = new QAction(this);
    QIcon iconStartCapture;
    iconStartCapture.addFile(QStringLiteral(":/res/images/start_capture.png"),
                 QSize(), QIcon::Normal, QIcon::Off);
    mStartCapture->setIcon(iconStartCapture);
    mStartCapture->setAutoRepeat(true);
    mStartCapture->setIconVisibleInMenu(true);
#else
    mStartCapture = mST->mMenuBar->mMenuCapture->mStart;
#endif
    addAction(mStartCapture);

#if 0
    mStopCapture = new QAction(this);
    QIcon iconStartCapture;
    iconStartCapture.addFile(QStringLiteral(":/res/images/stop_capture.png"),
                 QSize(), QIcon::Normal, QIcon::Off);
    mStopCapture->setIcon(iconStartCapture);
    mStopCapture->setAutoRepeat(true);
    mStopCapture->setIconVisibleInMenu(true);
#else
    mStopCapture = mST->mMenuBar->mMenuCapture->mStop;
#endif
    addAction(mStopCapture);

    // add a space widget to tool bar to make the action after than it
    // can right align on the tool bar
    QWidget *spacer;
    spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    addWidget(spacer);

    // go to the first position of the wave
    mGoBegin = new QAction(this);
    QIcon iconGoFirst;
    iconGoFirst.addFile(QStringLiteral(":/res/images/go_first.png"),
                 QSize(), QIcon::Normal, QIcon::Off);
    mGoBegin->setIcon(iconGoFirst);
    mGoBegin->setAutoRepeat(true);
    mGoBegin->setIconVisibleInMenu(true);
    addAction(mGoBegin);

    mGoPrev = new QAction(this);
    QIcon iconGoPrevious;
    iconGoPrevious.addFile(QStringLiteral(":/res/images/go_previous.png"),
                 QSize(), QIcon::Normal, QIcon::Off);
    mGoPrev->setIcon(iconGoPrevious);
    mGoPrev->setAutoRepeat(true);
    mGoPrev->setIconVisibleInMenu(true);
    addAction(mGoPrev);

    mGoNext = new QAction(this);
    QIcon iconGoNext;
    iconGoNext.addFile(QStringLiteral(":/res/images/go_next.png"),
                 QSize(), QIcon::Normal, QIcon::Off);
    mGoNext->setIcon(iconGoNext);
    mGoNext->setAutoRepeat(true);
    mGoNext->setIconVisibleInMenu(true);
    addAction(mGoNext);

    mGoLast = new QAction(this);
    QIcon iconGoLast;
    iconGoLast.addFile(QStringLiteral(":/res/images/go_last.png"),
                 QSize(), QIcon::Normal, QIcon::Off);
    mGoLast->setIcon(iconGoLast);
    mGoLast->setAutoRepeat(true);
    mGoLast->setIconVisibleInMenu(true);
    addAction(mGoLast);
}

void ToolBar::desetupUi()
{
}

void ToolBar::retranslateUi()
{
    mGoBegin->setToolTip(QApplication::translate(SIGNALTAP_CONTEXT,
                         "go to the first page of the wave", 0));
    mGoPrev->setToolTip(QApplication::translate(SIGNALTAP_CONTEXT,
                        "go to the previous page of the wave", 0));
    mGoNext->setToolTip(QApplication::translate(SIGNALTAP_CONTEXT,
                        "go to the next page of the wave", 0));

    mGoLast->setToolTip(QApplication::translate(SIGNALTAP_CONTEXT,
                        "go to the last page of the wave", 0));
}
