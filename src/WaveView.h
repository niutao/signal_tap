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
class WaveTabWidget;
class UsbDeviceInfo;
class UsbHandler;

class WaveView : public QGraphicsView
{
    Q_OBJECT
public:
    WaveView(SignalTap *st, QString *waveName = 0);
    ~WaveView();
    WaveTabWidget *mTab;
    WaveShow *mWaveShow;
    QString *mWaveName;
    QPushButton *mCloseButton;
    SignalTap *mST;
    //private fileds for ui
private:
    QHBoxLayout *mHL;
    QListView *mSignalView;
    QComboBox *mDevices;
    UsbHandler *mUsbHander;

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
    void onSceneRectChangedEvent(const QRectF & rect);

public slots:
    void onCloseButtonClicked();
    void deviceAdded(UsbDeviceInfo *usb);
    void deviceRemoved(UsbDeviceInfo *usb);
};

class WaveTabWidget: public QWidget
{
    Q_OBJECT
public:
    WaveTabWidget(WaveView *waveview);
    ~WaveTabWidget();
public:
    WaveView *getWaveView();
private:
    WaveView *mWaveView;
};

#endif // WAVEVIEW_H
