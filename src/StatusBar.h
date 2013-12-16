#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QStatusBar>
#include <QAction>

class SignalTap;

class StatusBar : public QStatusBar
{
public:
    StatusBar(SignalTap *st);
    ~StatusBar();
private:
    void setupUi();
    void desetupUi();
    void retranslateUi();
};

#endif // STATUSBAR_H
