#include "MenuEdit.h"
#include "SignalTap.h"
#include "MenuBar.h"
#include "WaveView.h"
#include "WaveShow.h"

MenuEdit::MenuEdit(MenuBar *parent) :
    QMenu(parent)
{
    mST = parent->mST;
    setupUi();
    retranslateUi();

    connect(mZoomIn, SIGNAL(triggered()), this, SLOT(onZoomInTriggered()));
    connect(mZoomOut, SIGNAL(triggered()), this, SLOT(onZoomOutTriggered()));
    connect(mTimeLine1, SIGNAL(triggered()), this, SLOT(onTimeLine1Triggered()));
    connect(mTimeLine2, SIGNAL(triggered()), this, SLOT(onTimeLine2Triggered()));
    connect(mClear, SIGNAL(triggered()), this, SLOT(onClearTriggered()));
    connect(mOptions, SIGNAL(triggered()), this, SLOT(onOptionsTriggered()));
}

MenuEdit::~MenuEdit()
{
    desetupUi();
}

void MenuEdit::setupUi()
{
    setTitle(QApplication::translate(SIGNALTAP_CONTEXT, "&Edit", 0));

    mZoomIn = new QAction(this);
    addAction(mZoomIn);
    mZoomOut = new QAction(this);
    addAction(mZoomOut);

    addSeparator();

    mTimeLine1 = new QAction(this);
    addAction(mTimeLine1);
    mTimeLine2 = new QAction(this);
    addAction(mTimeLine2);

    addSeparator();

    mClear = new QAction(this);
    addAction(mClear);

    addSeparator();

    mOptions = new QAction(this);
    addAction(mOptions);

}
void MenuEdit::retranslateUi()
{
    mZoomIn->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Zoom In", 0));
    mZoomOut->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Zoom Out", 0));

    mTimeLine1->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Place Time Line 1", 0));
    mTimeLine2->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Place Time Line 2", 0));

    mClear->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Clear", 0));
    mOptions->setText(QApplication::translate(SIGNALTAP_CONTEXT, "Options...", 0));
}

void MenuEdit::desetupUi()
{
    delete mZoomIn;
    delete mZoomOut;
    delete mTimeLine1;
    delete mTimeLine2;
    delete mClear;
    delete mOptions;
}

void MenuEdit::onZoomInTriggered()
{
}


void MenuEdit::onZoomOutTriggered()
{
}


void MenuEdit::onTimeLine1Triggered()
{
    WaveView *waveview;
    QPointF pos;

    waveview = mST->getCurrentWaveView();
    if (waveview == NULL)
        return;

    // waveview->cursor().pos().x() is the current x position of desktop screen
    // waveview->mST->pos().x() is the current x position of application window
    // waveview->pos().x() is the current x position of waveview on application window
    pos.setX(waveview->cursor().pos().x() - waveview->mST->pos().x() - waveview->pos().x());
    pos.setY(waveview->height());
    qDebug("onTimeLine1Triggered POS(%f, %f)\n", pos.x(), pos.y());
    waveview->mWaveShow->placeTimeLine(pos, WaveShow::TimeLine1);
}


void MenuEdit::onTimeLine2Triggered()
{
    WaveView *waveview;
    QPointF pos;

    waveview = mST->getCurrentWaveView();
    if (waveview == NULL)
        return;

    // waveview->cursor().pos().x() is the current x position of desktop screen
    // waveview->mST->pos().x() is the current x position of application window
    // waveview->pos().x() is the current x position of waveview on application window
    pos.setX(waveview->cursor().pos().x() - waveview->mST->pos().x() - waveview->pos().x());
    pos.setY(waveview->height());
    qDebug("onTimeLine2Triggered POS(%f, %f)\n", pos.x(), pos.y());
    waveview->mWaveShow->placeTimeLine(pos, WaveShow::TimeLine2);
}

void MenuEdit::onClearTriggered()
{
}


void MenuEdit::onOptionsTriggered()
{
}

