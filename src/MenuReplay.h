#ifndef MENUREPLAY_H
#define MENUREPLAY_H

#include <QObject>
#include <QMenu>
#include <QAction>
class SignalTap;
class MenuBar;

class MenuReplay : public QMenu
{
    Q_OBJECT
public:
    explicit MenuReplay(MenuBar *parent);
    ~MenuReplay();
private:
    QAction *actionReplayReplay;
    QAction *actionReplayReplayFromFile;
    void setupUi();
    void desetupUi();
    void retranslateUi();

signals:

public slots:

};

#endif // MENUEDIT_H
