//#define QT_NO_DEBUG_OUTPUT
#include "WaveTimeLine.h"
#include "WaveView.h"
#include "WaveShow.h"
#include <math.h>
#include <QPainter>
#include <QScrollBar>

WaveTimeLine::WaveTimeLine(WaveShow *waveshow)
{
    mCursor = new QCursor;

    setAcceptHoverEvents(true);
    setAcceptDrops(true);
    setZValue(0);

    // set the default pen color and style
    setPenStyle(Qt::magenta, Qt::DashLine, 1);
    setPen(mPen);

    mWaveShow = waveshow;

    mLastScrollBarPos = mWaveShow->mWaveView->horizontalScrollBar()->sliderPosition();
    mScrollBarOffset = 0;
}

void WaveTimeLine::setPenStyle(QColor color, Qt::PenStyle style, qreal width)
{
    mPen.setColor(color);
    mPen.setStyle(style);
    mPen.setWidthF(width);
    setPen(mPen);
}

void WaveTimeLine::setLine(qreal x1, qreal y1, qreal x2, qreal y2)
{
    QGraphicsLineItem::setLine(x1, y1, x2, y2);
}

void WaveTimeLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("%s\n", "mousePressEvent");
}

void WaveTimeLine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF current = event->pos();
    qreal timeLineCurrentPos;
    QScrollBar *bar = mWaveShow->mWaveView->horizontalScrollBar();

    mWaveShow->mWaveView->ensureVisible(this, 100, 0);
    if (mLastScrollBarPos != bar->sliderPosition()) {
        update();
        QGraphicsLineItem::mouseMoveEvent(event);

        mScrollBarOffset = bar->sliderPosition() - mLastScrollBarPos;
        mLastScrollBarPos = bar->sliderPosition();
        return;
    }

    timeLineCurrentPos = this->pos().x() + current.x() + mScrollBarOffset;
    qDebug("POS2(%f, %f, %f, %f, %f, %f)", mWaveShow->width(), this->line().x1(), timeLineCurrentPos,
           (qreal)bar->sliderPosition(), this->pos().x(), current.x());

    if (timeLineCurrentPos < mWaveShow->width() && timeLineCurrentPos > 0) {
        moveBy(current.x() - this->line().x1() + mScrollBarOffset, 0);
    }

    mScrollBarOffset = 0;

    update();
    QGraphicsLineItem::mouseMoveEvent(event);
}

void WaveTimeLine::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug("%s\n", "mouseReleaseEvent");
    update();
    QGraphicsLineItem::mouseReleaseEvent(event);
}

void WaveTimeLine::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug("%s\n", "hoverEnterEvent");
    mCursor->setShape(Qt::SplitHCursor);
    this->setCursor(*mCursor);
    QPointF p;
    p.setX(this->pos().x() + this->line().x1() + mScrollBarOffset);
    p.setY(this->pos().y() + this->line().y1());
    event->setPos(p);
    update();
    QGraphicsLineItem::hoverEnterEvent(event);
}

void WaveTimeLine::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{/*
    Q_UNUSED(event);
    qDebug("%s\n", "hoverMoveEvent");

    mCursor->setShape(Qt::SplitHCursor);
    this->setCursor(*mCursor);
    update();
    QGraphicsLineItem::hoverMoveEvent(event);*/
}

void WaveTimeLine::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug("%s\n", "hoverLeaveEvent");
    mCursor->setShape(Qt::ArrowCursor);
    this->setCursor(*mCursor);
    update();
    QGraphicsLineItem::hoverLeaveEvent(event);
}
