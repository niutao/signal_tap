#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

class SignalTap;
class MenuFile;
class MenuEdit;
class MenuView;
class MenuCapture;
class MenuReplay;
class MenuHelp;

class MenuBar : public QMenuBar
{
public:
    MenuBar(SignalTap *st);
    ~MenuBar();

private:
    SignalTap *st;
    MenuFile *mMenuFile;
    MenuEdit *mMenuEdit;
    MenuView *mMenuView;
    MenuCapture *mMenuCapture;
    MenuReplay *mMenuReplay;
    MenuHelp *mMenuHelp;
    void setupUi();
    void desetupUi();
    void retranslateUi();
};

#endif // MENUBAR_H
