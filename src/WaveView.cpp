#include "WaveView.h"
#include "SignalTap.h"
#include <errno.h>
#include "WaveTimeLine.h"
#include <QGraphicsItem>
#include <QScrollBar>
#include "WaveShow.h"

WaveView::WaveView(QWidget *parent):
    QGraphicsView(parent)
{
    setupUi();
    retranslateUi();

    mWidth = this->width();
    mHeight = this->height();
}

WaveView::~WaveView()
{
    desetupUi();
}

void WaveView::setupUi()
{
    mTab = new QWidget();
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(mTab->sizePolicy().hasHeightForWidth());
    mTab->setSizePolicy(sizePolicy1);

    mHL = new QHBoxLayout(mTab);
    mHL->setSpacing(6);
    mHL->setContentsMargins(11, 11, 11, 11);
    mHL->setContentsMargins(0, 0, 0, 0);

    mSignalView = new QTreeView(mTab);
    mSignalView->setEnabled(true);
    QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(mSignalView->sizePolicy().hasHeightForWidth());
    mSignalView->setSizePolicy(sizePolicy2);
    mSignalView->setMaximumSize(QSize(100, 16777215));
    mSignalView->setBaseSize(QSize(0, 0));

    mHL->addWidget(mSignalView);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //waveView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QBrush brush(QColor(0, 0, 0, 255));
    brush.setStyle(Qt::NoBrush);
    setBackgroundBrush(brush);

    mWaveShow = new WaveShow(this);
    setScene(mWaveShow);

    mHL->addWidget(this);
}
void WaveView::desetupUi()
{
    delete mWaveShow;
#if 0
    // beacuse the mSignalView and mHL are add to the widget
    // SignalTap->mTopTab, so when we free the mTopTab, the
    // system will free these three widget automatic
    delete mSignalView;
    delete mHL;
    delete mTab;
#endif
}
void WaveView::retranslateUi()
{

}

int WaveView::getWidth()
{
    return mWidth;
}

int WaveView::getHeight()
{
    return mHeight;
}

void WaveView::resizeEvent(QResizeEvent *event)
{
    QSize s = event->size();
    Q_UNUSED(s);

    QGraphicsScene *scene = this->scene();

    scene->setSceneRect(0, 0, scene->width(), event->size().height());

    mWidth = s.width();
    mHeight = s.height();

    qDebug("size(%f, %f)\n", scene->width(), scene->height());
}
