#ifndef MENUFILE_H
#define MENUFILE_H

#include <QObject>
#include <QMenu>

class SignalTap;
class MenuBar;

class MenuFile : public QMenu
{
    Q_OBJECT
public:
    MenuFile(MenuBar *parent, SignalTap *st);
    ~MenuFile();

public:
    QAction *mNew;
    QAction *mOpen;
    QAction *mSave;
    QAction *mExportAsBIN;
    QAction *mExportAsWLF;
    QAction *mPrint;
    QAction *mPrintSetup;
    QAction *mExit;
private:
    SignalTap *mST;
    void setupUi();
    void desetupUi();
    void retranslateUi();

signals:

public slots:
    void onNewTriggered();
    void onOpenTriggered();
    void onSaveTriggered();
    void onExportAsBINTriggered();
    void onExportAsWLFTriggered();
    void onPrintTriggered();
    void onPrintSetupTriggered();
    void onExitTriggered();
};

#endif // MENUFILE_H
