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
#include <QTabBar>
#include <QPushButton>

class WaveShow;
class SignalTap;

class WaveView : public QGraphicsView
{
    Q_OBJECT
public:
    WaveView(SignalTap *st, QString *waveName = 0);
    ~WaveView();
    QWidget *mTab;
    WaveShow *mWaveShow;
    QString *mWaveName;
    QPushButton *mCloseButton;

    //private fileds for ui
private:
    QHBoxLayout *mHL;
    QTreeView *mSignalView;
    SignalTap *mST;

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
    bool openWave(QString &wave);
signals:

public slots:
    void onCloseButtonClicked();

};

#endif // WAVEVIEW_H
