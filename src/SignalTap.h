#ifndef SIGNALTAP_H
#define SIGNALTAP_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QtWidgets>
#include <QTableWidget>
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

public:
    WaveView *mWaveView;

private:
    MenuBar *mMenuBar;
    ToolBar *mToolBar;
    QWidget *mTopWidget;
    QHBoxLayout *mTopHL;
    QTabWidget *mTopTab;
    StatusBar *mStatusBar;
    void setupUi();
    void desetupUi();
    void retranslateUi();

};

#endif // SIGNALTAP_H
