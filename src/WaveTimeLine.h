#ifndef WAVETIMELINE_H
#define WAVETIMELINE_H

#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QStyleOptionGraphicsItem>
#include <QCursor>

class WaveTimeLine : public QObject, public QGraphicsLineItem
{
    Q_OBJECT
public:
    WaveTimeLine();
    void setLine(qreal x1, qreal y1, qreal x2, qreal y2);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:

public slots:

private:
    QCursor* mCursor;
    QPointF mLastPos;
};

#endif // WAVETIMELINE_H
