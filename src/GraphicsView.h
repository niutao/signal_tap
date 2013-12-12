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
    int getWidth();
    int getHeight();
private:
    int mWidth;
    int mHeight;
};

#endif // GRAPHICSVIEW_H
