#include "ToolBar.h"
#include "SignalTap.h"

ToolBar::ToolBar(SignalTap *st):
    QToolBar(st)
{
    setupUi();
    retranslateUi();
}

ToolBar::~ToolBar()
{
    desetupUi();
}

void ToolBar::setupUi()
{
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());

    setSizePolicy(sizePolicy);
    setMaximumSize(QSize(16777215, 32));
    setIconSize(QSize(20, 20));

    actionToolBarNew = new QAction(this);
    actionToolBarNew->setObjectName(QStringLiteral("actionToolBarNew"));
    QIcon icon;
    icon.addFile(QStringLiteral(":/res/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
    icon.addFile(QStringLiteral(":/res/images/new.png"), QSize(), QIcon::Normal, QIcon::On);
    icon.addFile(QStringLiteral(":/res/images/new.png"), QSize(), QIcon::Active, QIcon::Off);
    icon.addFile(QStringLiteral(":/res/images/new.png"), QSize(), QIcon::Active, QIcon::On);
    actionToolBarNew->setIcon(icon);
    actionToolBarNew->setAutoRepeat(true);
    actionToolBarNew->setIconVisibleInMenu(true);

    addAction(actionToolBarNew);
}

void ToolBar::desetupUi()
{
}

void ToolBar::retranslateUi()
{
}
