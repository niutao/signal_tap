#ifndef MENUHELP_H
#define MENUHELP_H

#include <QObject>
#include <QMenu>
#include <QAction>
class SignalTap;
class MenuBar;

class MenuHelp : public QMenu
{
    Q_OBJECT
public:
    explicit MenuHelp(MenuBar *parent, SignalTap *st);
    ~MenuHelp();
private:
    QAction *actionHelpHelpTopic;
    QAction *actionHelpUpdateCheck;
    QAction *actionHelpAboutSignalTap;
    QAction *actionHelpAboutthis;
    void setupUi();
    void desetupUi();
    void retranslateUi();

signals:

public slots:

};

#endif // MENUEDIT_H
