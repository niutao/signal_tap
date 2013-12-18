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
private:
    QAction *actionCaptureStart;
    QAction *actionCaptureStop;
    QAction *actionCaptureStartWithTime;
    QAction *actionCaptureSetup;
    QAction *actionCaptureSampling;
    QAction *actionCaptureTrigger;

    void setupUi();
    void desetupUi();
    void retranslateUi();

signals:

public slots:

};

#endif // MENUEDIT_H
