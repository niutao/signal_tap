#include "GraphicsView.h"
#include <QResizeEvent>

GraphicsView::GraphicsView()
{

}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
    QSize s = event->size();
    QGraphicsScene *scene = this->scene();

    //scene->setSceneRect(0, 0, event->size().width(), event->size().height());
    scene->setSceneRect(0, 0, scene->width(), event->size().height());

    qDebug("size(%f, %f)\n", scene->width(), scene->height());
}

