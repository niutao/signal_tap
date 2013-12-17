#ifndef SIGNALTAP_H
#define SIGNALTAP_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QtWidgets>
#include <QTableWidget>
#include <QList>
#include "WaveView.h"

#define SIGNALTAP_CONTEXT "SignalTap"

class MenuBar;
class ToolBar;
class StatusBar;

class SignalTap : public QMainWindow
{
    Q_OBJECT
public:
    explicit SignalTap(QWidget *parent = 0);
    ~SignalTap();
    bool addWaveView();
    bool addWaveView(QString &wave);
    bool removeWaveView(int index);
    bool removeWaveView(WaveView *waveview);

public:
    MenuBar *mMenuBar;
    ToolBar *mToolBar;
    QWidget *mTopWidget;
    QHBoxLayout *mTopHL;
    QTabWidget *mTopTab;
    StatusBar *mStatusBar;
private:
    QList <WaveView *> mWaveViewList;
    void setupUi();
    void desetupUi();
    void retranslateUi();
};

#endif // SIGNALTAP_H
