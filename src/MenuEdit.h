#ifndef MENUEDIT_H
#define MENUEDIT_H

#include <QObject>
#include <QMenu>
#include <QAction>

class SignalTap;
class MenuBar;

class MenuEdit : public QMenu
{
    Q_OBJECT
public:
    explicit MenuEdit(MenuBar *parent);
    ~MenuEdit();
public:
    QAction *mZoomIn;
    QAction *mZoomOut;

    QAction *mTimeLine1;
    QAction *mTimeLine2;

    QAction *mClear;

    QAction *mOptions;
private:
    SignalTap *mST;
    void setupUi();
    void desetupUi();
    void retranslateUi();

signals:

public slots:
    void onZoomInTriggered();
    void onZoomOutTriggered();
    void onTimeLine1Triggered();
    void onTimeLine2Triggered();
    void onClearTriggered();
    void onOptionsTriggered();
};

#endif // MENUEDIT_H
