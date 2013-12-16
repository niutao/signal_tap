#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QToolBar>
#include <QAction>

class SignalTap;

class ToolBar : public QToolBar
{
public:
    ToolBar(SignalTap *st);
    ~ToolBar();
private:
    QAction *actionToolBarNew;
    void setupUi();
    void desetupUi();
    void retranslateUi();
};

#endif // TOOLBAR_H
