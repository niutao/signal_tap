#ifndef WAVEVIEW_H
#define WAVEVIEW_H

#include <QObject>
#include <QGraphicsScene>
#include <QStyle>
#include <QColor>

class WaveTimeLine;

class WaveView : public QGraphicsScene
{
    Q_OBJECT
public:
    WaveView(QGraphicsView *GraphicsView);
    enum Pen{TimeLine = 0, Scale, Move, Wave, MAX};

private:
    QGraphicsView *mGraphicsView;

    QPen mPens[MAX];

    WaveTimeLine *mTimeLine;

public:
    /** set the style of each pen */
    void setPenStyle(Pen pen, QColor color, Qt::PenStyle style, qreal width);

    QGraphicsLineItem *addLine(Pen pen, qreal x1, qreal y1, qreal x2, qreal y2);
    void drawTest();
    void drawPosedge(qreal x, qreal y, qreal height, qreal width, qreal count);
    void drawNegedge(qreal x, qreal y, qreal height, qreal width, qreal count);

signals:

public slots:

};

#endif // WAVEVIEW_H
