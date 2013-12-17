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

public:
    MenuFile *mMenuFile;
    MenuEdit *mMenuEdit;
    MenuView *mMenuView;
    MenuCapture *mMenuCapture;
    MenuReplay *mMenuReplay;
    MenuHelp *mMenuHelp;
private:
    SignalTap *mST;
    void setupUi();
    void desetupUi();
    void retranslateUi();
};

#endif // MENUBAR_H
