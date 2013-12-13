#ifndef WAVETIMELINE_H
#define WAVETIMELINE_H

#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QStyleOptionGraphicsItem>
#include <QCursor>

class WaveView;

class WaveTimeLine : public QObject, public QGraphicsLineItem
{
    Q_OBJECT
public:
    WaveTimeLine(WaveView *waveview);
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
    WaveView *mWaveView;

    int mLastScrollBarPos;
    int mScrollBarOffset;
};

#endif // WAVETIMELINE_H
