/********************************************************************************
** Form generated from reading UI file 'signaltap.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNALTAP_H
#define UI_SIGNALTAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignalTap
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExportAsBIN;
    QAction *actionExportAsWLF;
    QAction *actionPrint;
    QAction *actionPrintSetup;
    QAction *actionExit;
    QAction *actionClear;
    QAction *actionOptions;
    QAction *actionHelpTopic;
    QAction *actionUpdateCheck;
    QAction *actionAbout_SignalTap;
    QAction *actionStart;
    QAction *actionStop;
    QAction *actionStartWithTime;
    QAction *actionSetup;
    QAction *actionSampling;
    QAction *actionTrigger;
    QAction *actionReplay;
    QAction *actionReplayFromFile;
    QAction *actionToolBar;
    QAction *actionStatusBar;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionAuto_Mensure;
    QAction *actionToolBarNew;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayoutMain;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QTreeView *signalView;
    QGraphicsView *waveView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuCapture;
    QMenu *menuReplay;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SignalTap)
    {
        if (SignalTap->objectName().isEmpty())
            SignalTap->setObjectName(QStringLiteral("SignalTap"));
        SignalTap->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SignalTap->sizePolicy().hasHeightForWidth());
        SignalTap->setSizePolicy(sizePolicy);
        actionNew = new QAction(SignalTap);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(SignalTap);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(SignalTap);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExportAsBIN = new QAction(SignalTap);
        actionExportAsBIN->setObjectName(QStringLiteral("actionExportAsBIN"));
        actionExportAsWLF = new QAction(SignalTap);
        actionExportAsWLF->setObjectName(QStringLiteral("actionExportAsWLF"));
        actionPrint = new QAction(SignalTap);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        actionPrintSetup = new QAction(SignalTap);
        actionPrintSetup->setObjectName(QStringLiteral("actionPrintSetup"));
        actionExit = new QAction(SignalTap);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionClear = new QAction(SignalTap);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionOptions = new QAction(SignalTap);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionHelpTopic = new QAction(SignalTap);
        actionHelpTopic->setObjectName(QStringLiteral("actionHelpTopic"));
        actionUpdateCheck = new QAction(SignalTap);
        actionUpdateCheck->setObjectName(QStringLiteral("actionUpdateCheck"));
        actionAbout_SignalTap = new QAction(SignalTap);
        actionAbout_SignalTap->setObjectName(QStringLiteral("actionAbout_SignalTap"));
        actionStart = new QAction(SignalTap);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionStop = new QAction(SignalTap);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionStartWithTime = new QAction(SignalTap);
        actionStartWithTime->setObjectName(QStringLiteral("actionStartWithTime"));
        actionSetup = new QAction(SignalTap);
        actionSetup->setObjectName(QStringLiteral("actionSetup"));
        actionSampling = new QAction(SignalTap);
        actionSampling->setObjectName(QStringLiteral("actionSampling"));
        actionTrigger = new QAction(SignalTap);
        actionTrigger->setObjectName(QStringLiteral("actionTrigger"));
        actionReplay = new QAction(SignalTap);
        actionReplay->setObjectName(QStringLiteral("actionReplay"));
        actionReplayFromFile = new QAction(SignalTap);
        actionReplayFromFile->setObjectName(QStringLiteral("actionReplayFromFile"));
        actionToolBar = new QAction(SignalTap);
        actionToolBar->setObjectName(QStringLiteral("actionToolBar"));
        actionToolBar->setCheckable(true);
        actionStatusBar = new QAction(SignalTap);
        actionStatusBar->setObjectName(QStringLiteral("actionStatusBar"));
        actionStatusBar->setCheckable(true);
        actionZoom_In = new QAction(SignalTap);
        actionZoom_In->setObjectName(QStringLiteral("actionZoom_In"));
        actionZoom_Out = new QAction(SignalTap);
        actionZoom_Out->setObjectName(QStringLiteral("actionZoom_Out"));
        actionAuto_Mensure = new QAction(SignalTap);
        actionAuto_Mensure->setObjectName(QStringLiteral("actionAuto_Mensure"));
        actionAuto_Mensure->setCheckable(true);
        actionToolBarNew = new QAction(SignalTap);
        actionToolBarNew->setObjectName(QStringLiteral("actionToolBarNew"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral("res/images/new.png"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QStringLiteral("res/images/new.png"), QSize(), QIcon::Active, QIcon::Off);
        icon1.addFile(QStringLiteral("res/images/new.png"), QSize(), QIcon::Active, QIcon::On);
        actionToolBarNew->setIcon(icon1);
        actionToolBarNew->setAutoRepeat(true);
        actionToolBarNew->setIconVisibleInMenu(true);
        widget = new QWidget(SignalTap);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutMain = new QHBoxLayout();
        horizontalLayoutMain->setSpacing(6);
        horizontalLayoutMain->setObjectName(QStringLiteral("horizontalLayoutMain"));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        sizePolicy1.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy1);
        horizontalLayout_4 = new QHBoxLayout(tab);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        signalView = new QTreeView(tab);
        signalView->setObjectName(QStringLiteral("signalView"));
        signalView->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(signalView->sizePolicy().hasHeightForWidth());
        signalView->setSizePolicy(sizePolicy2);
        signalView->setMaximumSize(QSize(100, 16777215));
        signalView->setBaseSize(QSize(0, 0));

        horizontalLayout->addWidget(signalView);

        waveView = new QGraphicsView(tab);
        waveView->setObjectName(QStringLiteral("waveView"));
        waveView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        waveView->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        waveView->setForegroundBrush(brush1);

        horizontalLayout->addWidget(waveView);


        horizontalLayout_4->addLayout(horizontalLayout);

        tabWidget->addTab(tab, QString());

        horizontalLayoutMain->addWidget(tabWidget);


        horizontalLayout_2->addLayout(horizontalLayoutMain);

        SignalTap->setCentralWidget(widget);
        menuBar = new QMenuBar(SignalTap);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 19));
        menuBar->setMaximumSize(QSize(16777215, 16777215));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuCapture = new QMenu(menuBar);
        menuCapture->setObjectName(QStringLiteral("menuCapture"));
        menuReplay = new QMenu(menuBar);
        menuReplay->setObjectName(QStringLiteral("menuReplay"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        SignalTap->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SignalTap);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy3);
        mainToolBar->setMaximumSize(QSize(16777215, 32));
        mainToolBar->setIconSize(QSize(20, 20));
        SignalTap->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SignalTap);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SignalTap->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuCapture->menuAction());
        menuBar->addAction(menuReplay->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExportAsBIN);
        menuFile->addAction(actionExportAsWLF);
        menuFile->addSeparator();
        menuFile->addAction(actionPrint);
        menuFile->addAction(actionPrintSetup);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuCapture->addAction(actionStart);
        menuCapture->addAction(actionStop);
        menuCapture->addAction(actionStartWithTime);
        menuCapture->addSeparator();
        menuCapture->addAction(actionSetup);
        menuCapture->addAction(actionSampling);
        menuCapture->addAction(actionTrigger);
        menuReplay->addAction(actionReplay);
        menuReplay->addAction(actionReplayFromFile);
        menuEdit->addAction(actionZoom_In);
        menuEdit->addAction(actionZoom_Out);
        menuEdit->addAction(actionClear);
        menuEdit->addSeparator();
        menuEdit->addAction(actionOptions);
        menuView->addAction(actionToolBar);
        menuView->addAction(actionStatusBar);
        menuView->addAction(actionAuto_Mensure);
        menuHelp->addAction(actionHelpTopic);
        menuHelp->addAction(actionUpdateCheck);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout_SignalTap);
        mainToolBar->addAction(actionToolBarNew);

        retranslateUi(SignalTap);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SignalTap);
    } // setupUi

    void retranslateUi(QMainWindow *SignalTap)
    {
        SignalTap->setWindowTitle(QApplication::translate("SignalTap", "SignalTap", 0));
        actionNew->setText(QApplication::translate("SignalTap", "New", 0));
        actionOpen->setText(QApplication::translate("SignalTap", "Open...", 0));
        actionSave->setText(QApplication::translate("SignalTap", "Save", 0));
        actionExportAsBIN->setText(QApplication::translate("SignalTap", "Export as binrary...", 0));
        actionExportAsWLF->setText(QApplication::translate("SignalTap", "Export as WLF file...", 0));
        actionPrint->setText(QApplication::translate("SignalTap", "Print", 0));
        actionPrintSetup->setText(QApplication::translate("SignalTap", "Print Setup...", 0));
        actionExit->setText(QApplication::translate("SignalTap", "Exit", 0));
        actionClear->setText(QApplication::translate("SignalTap", "Clear", 0));
        actionOptions->setText(QApplication::translate("SignalTap", "Options...", 0));
        actionHelpTopic->setText(QApplication::translate("SignalTap", "Help Topic...", 0));
        actionUpdateCheck->setText(QApplication::translate("SignalTap", "Update Check...", 0));
        actionAbout_SignalTap->setText(QApplication::translate("SignalTap", "About SignalTap", 0));
        actionStart->setText(QApplication::translate("SignalTap", "Start", 0));
        actionStop->setText(QApplication::translate("SignalTap", "Stop", 0));
        actionStartWithTime->setText(QApplication::translate("SignalTap", "Start With Time...", 0));
        actionSetup->setText(QApplication::translate("SignalTap", "Setup...", 0));
        actionSampling->setText(QApplication::translate("SignalTap", "Sampling...", 0));
        actionTrigger->setText(QApplication::translate("SignalTap", "Trigger...", 0));
        actionReplay->setText(QApplication::translate("SignalTap", "Replay", 0));
#ifndef QT_NO_TOOLTIP
        actionReplay->setToolTip(QApplication::translate("SignalTap", "Replay current wave", 0));
#endif // QT_NO_TOOLTIP
        actionReplayFromFile->setText(QApplication::translate("SignalTap", "Replay from file...", 0));
        actionToolBar->setText(QApplication::translate("SignalTap", "ToolBar", 0));
        actionStatusBar->setText(QApplication::translate("SignalTap", "StatusBar", 0));
        actionZoom_In->setText(QApplication::translate("SignalTap", "Zoom In", 0));
        actionZoom_Out->setText(QApplication::translate("SignalTap", "Zoom Out", 0));
        actionAuto_Mensure->setText(QApplication::translate("SignalTap", "Auto Measure Window", 0));
        actionToolBarNew->setText(QApplication::translate("SignalTap", "ToolBarNew", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SignalTap", "Tab 1", 0));
        menuFile->setTitle(QApplication::translate("SignalTap", "&File", 0));
        menuCapture->setTitle(QApplication::translate("SignalTap", "&Capture", 0));
        menuReplay->setTitle(QApplication::translate("SignalTap", "&Replay", 0));
        menuEdit->setTitle(QApplication::translate("SignalTap", "&Edit", 0));
        menuView->setTitle(QApplication::translate("SignalTap", "&View", 0));
        menuHelp->setTitle(QApplication::translate("SignalTap", "&Help", 0));
    } // retranslateUi

};

namespace Ui {
    class SignalTap: public Ui_SignalTap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNALTAP_H
