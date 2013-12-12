#define QT_NO_DEBUG_OUTPUT
#include "GraphicsView.h"
#include <QResizeEvent>

GraphicsView::GraphicsView()
{
    mWidth = this->width();
    mHeight = this->height();
}

int GraphicsView::getWidth()
{
    return mWidth;
}

int GraphicsView::getHeight()
{
    return mHeight;
}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
    QSize s = event->size();
    Q_UNUSED(s);

    QGraphicsScene *scene = this->scene();

    scene->setSceneRect(0, 0, scene->width(), event->size().height());

    mWidth = s.width();
    mHeight = s.height();

    qDebug("size(%f, %f)\n", scene->width(), scene->height());
}

