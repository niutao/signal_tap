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
    SignalTap *mST;

    // action from MenuFile
    QAction *mNew;
    QAction *mOpen;

    // action from MenuCapture
    QAction *mStartCapture;
    QAction *mStopCapture;

    QAction *mGoBegin;
    QAction *mGoPrev;
    QAction *mGoNext;
    QAction *mGoLast;
    void setupUi();
    void desetupUi();
    void retranslateUi();
};

#endif // TOOLBAR_H
