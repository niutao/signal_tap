#include "WaveView.h"
#include "SignalTap.h"
#include <errno.h>
#include "WaveTimeLine.h"
#include <QGraphicsItem>
#include "GraphicsView.h"
#include <QScrollBar>

WaveView::WaveView(QObject *parent):
    QGraphicsScene(parent)
{
    setupUi();

    mTimeLine = new WaveTimeLine(this);

    setBackgroundBrush(Qt::black);

    setPenStyle(Wave, Qt::green, Qt::SolidLine, 1);
    setPenStyle(Move, Qt::magenta, Qt::DashLine, 1);

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

        mGraphicsView = new GraphicsView();

        mGraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        //waveView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        mGraphicsView->setBackgroundBrush(brush);

        mGraphicsView->setScene(this);

        mHL->addWidget(mGraphicsView);

        //tabWidget->addTab(tab, QString());
}

void WaveView::setPenStyle(WaveView::Pen pen, QColor color,
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

QGraphicsLineItem *WaveView::addLine(Pen pen, qreal x1, qreal y1, qreal x2, qreal y2)
{
    return QGraphicsScene::addLine(x1, y1, x2, y2, mPens[pen]);
}

void WaveView::drawPosedge(qreal x, qreal y, qreal height, qreal width, qreal count)
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

void WaveView::drawNegedge(qreal x, qreal y, qreal height, qreal width, qreal count)
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
void WaveView::drawTest()
{
    qreal width, height;
    qreal x, y;

    x = 0;
    y = 25;
    width = 10;
    height = 20;

    for (int i = 0; i < 10000; i += 2) {
        drawPosedge(x + width * i, y, height, width, 1);
        drawNegedge(x + width * (i + 1), y - height, height, width, 1);
    }


    /*
    for (int i = 0; i < 10000; i += 2) {
        drawPosedge(x + width * i, y, height, width, 1);
        drawNegedge(x + width * (i + 1), y - height, height, width, 1);
    }
    */
    x = 0;
    y = 55;
    width = 40;
    height = 20;

    for (int i = 0; i < 500; i += 2) {
        drawPosedge(x + width * i, y, height, width, 1);
        drawNegedge(x + width * (i + 1), y - height, height, width, 1);
    }
#if 0
    QList<QGraphicsItem *> list;
    list = this->items(0, 0, 50000, mGraphicsView->height(), Qt::IntersectsItemShape, Qt::AscendingOrder);
    qDebug("list.count = %d\n", list.count());
    foreach (QGraphicsItem *item, list) {
        this->removeItem(item);
    }
#endif
    x = 10000 * 10;
    y = 25;
    width = 10;
    height = 20;

    for (int i = 0; i < 40000; i += 2) {
        drawPosedge(x + width * i, y, height, width, 1);
        drawNegedge(x + width * (i + 1), y - height, height, width, 1);
    }


    mTimeLine->setPen(mPens[Move]);
    mTimeLine->setLine(100, 0, 100, this->width());

    addItem(mTimeLine);
}


