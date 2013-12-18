#ifndef WAVESHOW_H
#define WAVESHOW_H

#include <QObject>
#include <QGraphicsScene>
#include <QStyle>
#include <QColor>
#include <QHBoxLayout>
#include <QTreeView>
#include <QtWidgets>
#include <QMenu>
#include <QPointF>

class WaveView;
class WaveTimeLine;

class WaveShow : public QGraphicsScene
{
    Q_OBJECT
public:
    WaveShow(WaveView *parent);
    ~WaveShow();

    WaveView *mWaveView;
    enum TimeLine {TimeLine1, TimeLine2};
private:
    enum Pen{Scale = 0, Move, Wave, MAX};
    WaveTimeLine *mTimeLines[2];
    bool mTimeLinePlaced[2];
    QPen mPens[MAX];
    QMenu *mContextMenu;

    void setupUi();
    void desetupUi();
    void retranslateUi();
public:
    /** set the style of each pen */
    void setPenStyle(Pen pen, QColor color, Qt::PenStyle style, qreal width);

    QGraphicsLineItem *addLine(Pen pen, qreal x1, qreal y1, qreal x2, qreal y2);
    void drawTest();
    void drawPosedge(qreal x, qreal y, qreal height, qreal width, qreal count);
    void drawNegedge(qreal x, qreal y, qreal height, qreal width, qreal count);

    bool setWaveWidth(int width);
    void placeTimeLine(QPointF pos, TimeLine timeline);

protected:
    //override the parent function to handle the right mouse event
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

public slots:
    void onSceneRectChangedEvent(const QRectF & rect);
};

#endif // WAVESHOW_H
