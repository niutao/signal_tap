#ifndef MENUFILE_H
#define MENUFILE_H

#include <QObject>
//#include "signaltap.h"

class SignalTap;

class MenuFile : public QObject
{
    Q_OBJECT
public:
    MenuFile(SignalTap *st);

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
