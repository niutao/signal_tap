#ifndef WAVESHOW_H
#define WAVESHOW_H

#include <QObject>
#include <QGraphicsScene>
#include <QStyle>
#include <QColor>
#include <QHBoxLayout>
#include <QTreeView>
#include <QtWidgets>

class WaveView;
class WaveTimeLine;

class WaveShow : public QGraphicsScene
{
public:
    WaveShow(WaveView *parent);
    WaveView *mWaveView;
    ~WaveShow();
    enum Pen{TimeLine = 0, Scale, Move, Wave, MAX};
    WaveTimeLine *mTimeLine;
private:
    QPen mPens[MAX];

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
};

#endif // WAVESHOW_H
