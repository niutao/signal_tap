#include "WaveTimeLine.h"
#include "WaveView.h"
#include "GraphicsView.h"
#include <math.h>
#include <QPainter>
#include <QScrollBar>

WaveTimeLine::WaveTimeLine(WaveView *waveview)
{
    mCursor = new QCursor;

    setAcceptHoverEvents(true);
    setAcceptDrops(true);
    setZValue(0);

    mLastPos.setX(0);
    mLastPos.setY(0);

    mWaveView = waveview;

}
void WaveTimeLine::setLine(qreal x1, qreal y1, qreal x2, qreal y2)
{

    this->mLastPos.setX(x1);
    this->mLastPos.setY(y1);

    QGraphicsLineItem::setLine(x1, y1, x2, y2);
}

void WaveTimeLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("%s\n", "mousePressEvent");
}
int a = 0;
void WaveTimeLine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF current = event->pos();
    QPointF offset;
    QLineF line;
    qreal windowRightPos, timeLineCurrentPos;
    QScrollBar *bar = mWaveView->mGraphicsView->horizontalScrollBar();
    offset = current - mLastPos;

    windowRightPos = (qreal)mWaveView->mGraphicsView->getWidth();
    timeLineCurrentPos = this->line().x1() + this->pos().x() - bar->sliderPosition();



    qDebug("POS(%f, %f, %f, %f, %d)", windowRightPos, timeLineCurrentPos,
           this->line().x1(), this->pos().x(), bar->sliderPosition());

    // the time line will approach the right border
    if (timeLineCurrentPos + 100.0 >= windowRightPos) {
#if 1
        int wantPos = bar->sliderPosition() + 100;
        if (wantPos <= bar->maximum() * bar->singleStep()) {
            if (a++ < 200)
                bar->setSliderPosition(wantPos);
        }
#endif
        //mWaveView->mGraphicsView->centerOn((timeLineCurrentPos + 100)/ 2, mWaveView->height() / 2);
    }


    //qDebug("(%f, %f), (%f, %f)\n", mLastPos.x(), mLastPos.y(),
      //     current.x(), current.y());
    if (fabs(offset.x()) >= 19.0) {
        //qDebug("offsetx = %f\n", offset.x());
        moveBy(offset.x() + 1, 0);
        line = this->line();
        mLastPos.setX(line.x1());
        mLastPos.setY(line.y1());

    }

    update();
    QGraphicsLineItem::mouseMoveEvent(event);
}

void WaveTimeLine::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("%s\n", "mouseReleaseEvent");
}

void WaveTimeLine::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug("%s\n", "hoverEnterEvent");
    mCursor->setShape(Qt::SplitHCursor);
    setCursor(*mCursor);

    update();
    QGraphicsLineItem::hoverEnterEvent(event);
}

void WaveTimeLine::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug("%s\n", "hoverMoveEvent");
    //mCursor->setShape(Qt::SplitHCursor);
    //setCursor(*mCursor);
    QPointF point = event->screenPos();
    qDebug("Point(%f, %f)\n", point.x(), point.y());
    //mCursor->setPos(point.x() + 2, point.y());
}

void WaveTimeLine::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug("%s\n", "hoverLeaveEvent");
    mCursor->setShape(Qt::ArrowCursor);
    this->setCursor(*mCursor);
    update();
    QGraphicsLineItem::hoverLeaveEvent(event);
}
