#ifndef WAVEVIEW_H
#define WAVEVIEW_H

#include <QObject>
#include <QGraphicsScene>
#include <QStyle>
#include <QColor>
#include <QHBoxLayout>
#include <QTreeView>
#include <QtWidgets>

class WaveTimeLine;
class GraphicsView;

class WaveView : public QGraphicsScene
{
    Q_OBJECT
public:
    WaveView(QObject *parent);
    enum Pen{TimeLine = 0, Scale, Move, Wave, MAX};
    GraphicsView *mGraphicsView;

private:
    QPen mPens[MAX];
    WaveTimeLine *mTimeLine;

private:
    QWidget *mTab;
    QHBoxLayout *mHL;
    QTreeView *mSignalView;
    void setupUi();

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
