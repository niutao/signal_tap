#ifndef MENUEDIT_H
#define MENUEDIT_H

#include <QObject>
#include <QMenu>
#include <QAction>

class SignalTap;
class MenuBar;

class MenuEdit : public QMenu
{
    Q_OBJECT
public:
    explicit MenuEdit(MenuBar *parent, SignalTap *st);
    ~MenuEdit();
private:
    QAction *actionEditClear;
    QAction *actionEditOptions;
    QAction *actionEditZoomIn;
    QAction *actionEditZoomOut;
    void setupUi();
    void desetupUi();
    void retranslateUi();

signals:

public slots:

};

#endif // MENUEDIT_H
