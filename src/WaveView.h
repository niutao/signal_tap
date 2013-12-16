#ifndef WAVEVIEW_H
#define WAVEVIEW_H

#include <QObject>
#include <QGraphicsScene>
#include <QStyle>
#include <QColor>
#include <QHBoxLayout>
#include <QTreeView>
#include <QtWidgets>
#include <QGraphicsView>

class WaveShow;

class WaveView : public QGraphicsView
{
    Q_OBJECT
public:
    WaveView(QWidget *parent);
    ~WaveView();
    QWidget *mTab;
    WaveShow *mWaveShow;

    //private fileds for ui
private:
    QHBoxLayout *mHL;
    QTreeView *mSignalView;

    int mWidth;
    int mHeight;
    void setupUi();
    void desetupUi();
    void retranslateUi();
protected:
    void resizeEvent(QResizeEvent *event);

public:
    int getWidth();
    int getHeight();

signals:

public slots:

};

#endif // WAVEVIEW_H
