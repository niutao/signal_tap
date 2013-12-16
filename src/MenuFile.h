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

private:
    QAction *actionFileNew;
    QAction *actionFileOpen;
    QAction *actionFileSave;
    QAction *actionFileExportAsBIN;
    QAction *actionFileExportAsWLF;
    QAction *actionFilePrint;
    QAction *actionFilePrintSetup;
    QAction *actionFileExit;

    void setupUi();
    void desetupUi();
    void retranslateUi();

signals:

public slots:
    void actionFileNewTriggered();
    void actionFileOpenTriggered();
    void actionFileSaveTriggered();
    void actionFileExportAsBINTriggered();
    void actionFileExportAsWLFTriggered();
    void actionFilePrintTriggered();
    void actionFilePrintSetupTriggered();
    void actionFileExitTriggered();
};

#endif // MENUFILE_H
