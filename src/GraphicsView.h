#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView();

protected:
    void resizeEvent(QResizeEvent *event);

public:

private:
};

#endif // GRAPHICSVIEW_H
