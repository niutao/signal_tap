#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <QObject>
#include <QMenu>
#include <QAction>

class SignalTap;
class MenuBar;

class MenuView : public QMenu
{
    Q_OBJECT
public:
    explicit MenuView(MenuBar *parent, SignalTap *st);
    ~MenuView();
private:
    QAction *actionViewToolBar;
    QAction *actionViewStatusBar;
    QAction *actionViewAutoMensure;
    void setupUi();
    void desetupUi();
    void retranslateUi();

signals:

public slots:

};

#endif // MENUEDIT_H
