#ifndef MENUCAPTURE_H
#define MENUCAPTURE_H

#include <QObject>
#include <QMenu>
#include <QAction>

class SignalTap;
class MenuBar;

class MenuCapture : public QMenu
{
    Q_OBJECT
public:
    explicit MenuCapture(MenuBar *parent);
    ~MenuCapture();

public:
    QAction *mStart;
    QAction *mStop;
    enum Menber{Start, Stop};
private:
    SignalTap *mST;

    QAction *mStartWithTime;
    QAction *mSetup;
    QAction *mSampling;
    QAction *mTrigger;

    void setupUi();
    void desetupUi();
    void retranslateUi();

signals:

public slots:
    void onStartTriggered();
    void onStopTriggered();
    void onStartWithTimeTriggered();
    void onSetupTriggered();
    void onSamplingTriggered();
    void onTriggerTriggered();

    void setMenuEnable(Menber menber, bool state);
};

#endif // MENUEDIT_H
