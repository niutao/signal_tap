#include <errno.h>
#include "MenuCapture.h"
#include "WaveShow.h"
#include "WaveView.h"
#include "MenuBar.h"
#include "MenuEdit.h"
#include "WaveTimeLine.h"
#include "SignalTap.h"
#include <QCursor>
#include <QMenu>

WaveShow::WaveShow(WaveView *parent):
    QGraphicsScene(parent)
{
    mWaveView = parent;
    setupUi();
    retranslateUi();

    // set the default rect of GraphicsScene
    this->setSceneRect(0, 0,
                       mWaveView->mST->mTopTab->width() - parent->width() - 8,
                       mWaveView->mST->mTopTab->height());

    mTimeLines[TimeLine1] = new WaveTimeLine(this);
    mTimeLines[TimeLine1]->setPenStyle(Qt::magenta, Qt::DashLine, 1);
    mTimeLines[TimeLine2] = new WaveTimeLine(this);
    mTimeLines[TimeLine2]->setPenStyle(Qt::yellow, Qt::DashLine, 1);

    mTimeLinePlaced[TimeLine1] = false;
    mTimeLinePlaced[TimeLine2] = false;

    connect(parent, SIGNAL(onSceneRectChangedEvent(QRectF)),
            this, SLOT(onSceneRectChangedEvent(QRectF)));
}

WaveShow::~WaveShow()
{
    desetupUi();
}
void WaveShow::setupUi()
{
    setBackgroundBrush(Qt::black);
    setPenStyle(Wave, Qt::green, Qt::SolidLine, 1);
    setPenStyle(Move, Qt::magenta, Qt::DashLine, 1);

    // create the context menu
    mContextMenu = new QMenu();
    mContextMenu->addAction(mWaveView->mST->mMenuBar->mMenuEdit->mZoomIn);
    mContextMenu->addAction(mWaveView->mST->mMenuBar->mMenuEdit->mZoomOut);
    mContextMenu->addSeparator();
    mContextMenu->addAction(mWaveView->mST->mMenuBar->mMenuEdit->mTimeLine1);
    mContextMenu->addAction(mWaveView->mST->mMenuBar->mMenuEdit->mTimeLine2);
}
void WaveShow::retranslateUi()
{

}

void WaveShow::desetupUi()
{
    delete mTimeLines[TimeLine1];
    delete mTimeLines[TimeLine2];
}

void WaveShow::setPenStyle(Pen pen, QColor color,
                           Qt::PenStyle style, qreal width)
{
    QPen *qpen;

    if (pen < 0 || pen >= MAX)
        throw -EINVAL;

    qpen = &mPens[pen];

    qpen->setColor(color);
    qpen->setStyle(style);
    qpen->setWidthF(width);
}

QGraphicsLineItem *WaveShow::addLine(Pen pen, qreal x1, qreal y1, qreal x2, qreal y2)
{
    return QGraphicsScene::addLine(x1, y1, x2, y2, mPens[pen]);
}
bool WaveShow::setWaveWidth(int width)
{
    this->setSceneRect(0, 0, width, this->height());
}

void WaveShow::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    qDebug("right mouse\n");
    QPoint pos = event->screenPos();

    mContextMenu->exec(pos);
}

void WaveShow::placeTimeLine(QPointF pos, TimeLine timeline)
{
    if (mTimeLinePlaced[timeline])
        removeItem(mTimeLines[timeline]);

    mTimeLines[timeline]->setLine(pos.x(), 0, pos.x(), this->height());
    addItem(mTimeLines[timeline]);
    mTimeLinePlaced[timeline] = true;
}

void WaveShow::onSceneRectChangedEvent(const QRectF &rect)
{
    WaveTimeLine *tl;
    qDebug("RECT(%f, %f, %f, %f)\n", rect.x(), rect.y(), rect.width(), rect.height());

    for (int timeline = TimeLine1; timeline < TimeLine2; timeline++) {
        tl = mTimeLines[timeline];
        if (mTimeLinePlaced[timeline])
            tl->setLine(
                        tl->line().x1(),
                        tl->line().y1(),
                        tl->line().x1(),
                        rect.height());
    }

}

void WaveShow::drawPosedge(qreal x, qreal y, qreal height, qreal width, qreal count)
{
    qreal x1, y1;
    qreal x2, y2;
    qreal xx, yy;

    x1 = x;
    y1 = y;
    x2 = x;
    y2 = y - height;

    addLine(Wave, x, y, x, y2); // draw posedge
    addLine(Wave, x, y2, x + width, y2);

    yy = y - height;

    for (int i = 0; i < count; i++) {
        x2 = x + width * i;
        xx = x2 + width;

        addLine(Wave, x2, yy, xx, yy);
    }
}

void WaveShow::drawNegedge(qreal x, qreal y, qreal height, qreal width, qreal count)
{
    qreal x1, y1;
    qreal x2, y2;
    qreal xx, yy;

    x1 = x;
    y1 = y;
    x2 = x;
    y2 = y + height;

    addLine(Wave, x, y, x, y2); // draw posedge
    addLine(Wave, x, y2, x + width, y2);

    yy = y + height;

    for (int i = 0; i < count; i++) {
        x2 = x + width * i;
        xx = x2 + width;

        addLine(Wave, x2, yy, xx, yy);
    }
}

void WaveShow::drawTest()
{
    qreal width, height;
    qreal x, y;

    x = 0;
    y = 25;
    width = 10;
    height = 20;

    for (int i = 0; i < 1000; i += 2) {
        drawPosedge(x + width * i, y, height, width, 1);
        drawNegedge(x + width * (i + 1), y - height, height, width, 1);
    }

    x = 0;
    y = 55;
    width = 40;
    height = 20;

    for (int i = 0; i < 500; i += 2) {
        drawPosedge(x + width * i, y, height, width, 1);
        drawNegedge(x + width * (i + 1), y - height, height, width, 1);
    }

    setWaveWidth(20000);
}
