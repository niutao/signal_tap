#ifndef SIGNALTAP_H
#define SIGNALTAP_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QtWidgets>
#include <QTableWidget>
#include <QList>

#define SIGNALTAP_CONTEXT "SignalTap"

class MenuBar;
class ToolBar;
class StatusBar;
class WaveView;
class UsbManager;

class SignalTap : public QMainWindow
{
    Q_OBJECT
public:
    explicit SignalTap(QWidget *parent = 0);
    ~SignalTap();
    WaveView *addWaveView();
    WaveView *addWaveView(QString &wave);
    bool removeWaveView(int index);
    bool removeWaveView(WaveView *waveview);
    WaveView *getCurrentWaveView();

    void startSignalTap();
    void stopSignalTap();

public:
    MenuBar *mMenuBar;
    ToolBar *mToolBar;
    QWidget *mTopWidget;
    QHBoxLayout *mTopHL;
    QTabWidget *mTopTab;
    StatusBar *mStatusBar;
    UsbManager *mUsbManager;
private:
    QList <WaveView *> mWaveViewList;
    void setupUi();
    void desetupUi();
    void retranslateUi();
};

#endif // SIGNALTAP_H
