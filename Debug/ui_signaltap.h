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

class GraphicsView;
QT_BEGIN_NAMESPACE

class Ui_SignalTap
{
public:
    QAction *actionFileNew;
    QAction *actionFileOpen;
    QAction *actionFileSave;
    QAction *actionFileExportAsBIN;
    QAction *actionFileExportAsWLF;
    QAction *actionFilePrint;
    QAction *actionFilePrintSetup;
    QAction *actionFileExit;
    QAction *actionEditClear;
    QAction *actionEditOptions;
    QAction *actionHelpHelpTopic;
    QAction *actionHelpUpdateCheck;
    QAction *actionHelpAboutSignalTap;
    QAction *actionCaptureStart;
    QAction *actionCaptureStop;
    QAction *actionCaptureStartWithTime;
    QAction *actionCaptureSetup;
    QAction *actionCaptureSampling;
    QAction *actionCaptureTrigger;
    QAction *actionReplayReplay;
    QAction *actionReplayReplayFromFile;
    QAction *actionViewToolBar;
    QAction *actionViewStatusBar;
    QAction *actionEditZoomIn;
    QAction *actionEditZoomOut;
    QAction *actionViewAutoMensure;
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
        actionFileNew = new QAction(SignalTap);
        actionFileNew->setObjectName(QStringLiteral("actionFileNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFileNew->setIcon(icon);
        actionFileOpen = new QAction(SignalTap);
        actionFileOpen->setObjectName(QStringLiteral("actionFileOpen"));
        actionFileSave = new QAction(SignalTap);
        actionFileSave->setObjectName(QStringLiteral("actionFileSave"));
        actionFileExportAsBIN = new QAction(SignalTap);
        actionFileExportAsBIN->setObjectName(QStringLiteral("actionFileExportAsBIN"));
        actionFileExportAsWLF = new QAction(SignalTap);
        actionFileExportAsWLF->setObjectName(QStringLiteral("actionFileExportAsWLF"));
        actionFilePrint = new QAction(SignalTap);
        actionFilePrint->setObjectName(QStringLiteral("actionFilePrint"));
        actionFilePrintSetup = new QAction(SignalTap);
        actionFilePrintSetup->setObjectName(QStringLiteral("actionFilePrintSetup"));
        actionFileExit = new QAction(SignalTap);
        actionFileExit->setObjectName(QStringLiteral("actionFileExit"));
        actionEditClear = new QAction(SignalTap);
        actionEditClear->setObjectName(QStringLiteral("actionEditClear"));
        actionEditOptions = new QAction(SignalTap);
        actionEditOptions->setObjectName(QStringLiteral("actionEditOptions"));
        actionHelpHelpTopic = new QAction(SignalTap);
        actionHelpHelpTopic->setObjectName(QStringLiteral("actionHelpHelpTopic"));
        actionHelpUpdateCheck = new QAction(SignalTap);
        actionHelpUpdateCheck->setObjectName(QStringLiteral("actionHelpUpdateCheck"));
        actionHelpAboutSignalTap = new QAction(SignalTap);
        actionHelpAboutSignalTap->setObjectName(QStringLiteral("actionHelpAboutSignalTap"));
        actionCaptureStart = new QAction(SignalTap);
        actionCaptureStart->setObjectName(QStringLiteral("actionCaptureStart"));
        actionCaptureStop = new QAction(SignalTap);
        actionCaptureStop->setObjectName(QStringLiteral("actionCaptureStop"));
        actionCaptureStartWithTime = new QAction(SignalTap);
        actionCaptureStartWithTime->setObjectName(QStringLiteral("actionCaptureStartWithTime"));
        actionCaptureSetup = new QAction(SignalTap);
        actionCaptureSetup->setObjectName(QStringLiteral("actionCaptureSetup"));
        actionCaptureSampling = new QAction(SignalTap);
        actionCaptureSampling->setObjectName(QStringLiteral("actionCaptureSampling"));
        actionCaptureTrigger = new QAction(SignalTap);
        actionCaptureTrigger->setObjectName(QStringLiteral("actionCaptureTrigger"));
        actionReplayReplay = new QAction(SignalTap);
        actionReplayReplay->setObjectName(QStringLiteral("actionReplayReplay"));
        actionReplayReplayFromFile = new QAction(SignalTap);
        actionReplayReplayFromFile->setObjectName(QStringLiteral("actionReplayReplayFromFile"));
        actionViewToolBar = new QAction(SignalTap);
        actionViewToolBar->setObjectName(QStringLiteral("actionViewToolBar"));
        actionViewToolBar->setCheckable(true);
        actionViewStatusBar = new QAction(SignalTap);
        actionViewStatusBar->setObjectName(QStringLiteral("actionViewStatusBar"));
        actionViewStatusBar->setCheckable(true);
        actionEditZoomIn = new QAction(SignalTap);
        actionEditZoomIn->setObjectName(QStringLiteral("actionEditZoomIn"));
        actionEditZoomOut = new QAction(SignalTap);
        actionEditZoomOut->setObjectName(QStringLiteral("actionEditZoomOut"));
        actionViewAutoMensure = new QAction(SignalTap);
        actionViewAutoMensure->setObjectName(QStringLiteral("actionViewAutoMensure"));
        actionViewAutoMensure->setCheckable(true);
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

        waveView = new GraphicsView();//new QGraphicsView(tab);
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
        menuFile->addAction(actionFileNew);
        menuFile->addAction(actionFileOpen);
        menuFile->addAction(actionFileSave);
        menuFile->addSeparator();
        menuFile->addAction(actionFileExportAsBIN);
        menuFile->addAction(actionFileExportAsWLF);
        menuFile->addSeparator();
        menuFile->addAction(actionFilePrint);
        menuFile->addAction(actionFilePrintSetup);
        menuFile->addSeparator();
        menuFile->addAction(actionFileExit);
        menuCapture->addAction(actionCaptureStart);
        menuCapture->addAction(actionCaptureStop);
        menuCapture->addAction(actionCaptureStartWithTime);
        menuCapture->addSeparator();
        menuCapture->addAction(actionCaptureSetup);
        menuCapture->addAction(actionCaptureSampling);
        menuCapture->addAction(actionCaptureTrigger);
        menuReplay->addAction(actionReplayReplay);
        menuReplay->addAction(actionReplayReplayFromFile);
        menuEdit->addAction(actionEditZoomIn);
        menuEdit->addAction(actionEditZoomOut);
        menuEdit->addAction(actionEditClear);
        menuEdit->addSeparator();
        menuEdit->addAction(actionEditOptions);
        menuView->addAction(actionViewToolBar);
        menuView->addAction(actionViewStatusBar);
        menuView->addAction(actionViewAutoMensure);
        menuHelp->addAction(actionHelpHelpTopic);
        menuHelp->addAction(actionHelpUpdateCheck);
        menuHelp->addSeparator();
        menuHelp->addAction(actionHelpAboutSignalTap);
        mainToolBar->addAction(actionToolBarNew);

        retranslateUi(SignalTap);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SignalTap);
    } // setupUi

    void retranslateUi(QMainWindow *SignalTap)
    {
        SignalTap->setWindowTitle(QApplication::translate("SignalTap", "SignalTap", 0));
        actionFileNew->setText(QApplication::translate("SignalTap", "New", 0));
        actionFileOpen->setText(QApplication::translate("SignalTap", "Open...", 0));
        actionFileSave->setText(QApplication::translate("SignalTap", "Save", 0));
        actionFileExportAsBIN->setText(QApplication::translate("SignalTap", "Export as binrary...", 0));
        actionFileExportAsWLF->setText(QApplication::translate("SignalTap", "Export as WLF file...", 0));
        actionFilePrint->setText(QApplication::translate("SignalTap", "Print", 0));
        actionFilePrintSetup->setText(QApplication::translate("SignalTap", "Print Setup...", 0));
        actionFileExit->setText(QApplication::translate("SignalTap", "Exit", 0));
        actionEditClear->setText(QApplication::translate("SignalTap", "Clear", 0));
        actionEditOptions->setText(QApplication::translate("SignalTap", "Options...", 0));
        actionHelpHelpTopic->setText(QApplication::translate("SignalTap", "Help Topic...", 0));
        actionHelpUpdateCheck->setText(QApplication::translate("SignalTap", "Update Check...", 0));
        actionHelpAboutSignalTap->setText(QApplication::translate("SignalTap", "About SignalTap", 0));
        actionCaptureStart->setText(QApplication::translate("SignalTap", "Start", 0));
        actionCaptureStop->setText(QApplication::translate("SignalTap", "Stop", 0));
        actionCaptureStartWithTime->setText(QApplication::translate("SignalTap", "Start With Time...", 0));
        actionCaptureSetup->setText(QApplication::translate("SignalTap", "Setup...", 0));
        actionCaptureSampling->setText(QApplication::translate("SignalTap", "Sampling...", 0));
        actionCaptureTrigger->setText(QApplication::translate("SignalTap", "Trigger...", 0));
        actionReplayReplay->setText(QApplication::translate("SignalTap", "Replay", 0));
#ifndef QT_NO_TOOLTIP
        actionReplayReplay->setToolTip(QApplication::translate("SignalTap", "Replay current wave", 0));
#endif // QT_NO_TOOLTIP
        actionReplayReplayFromFile->setText(QApplication::translate("SignalTap", "Replay from file...", 0));
        actionViewToolBar->setText(QApplication::translate("SignalTap", "ToolBar", 0));
        actionViewStatusBar->setText(QApplication::translate("SignalTap", "StatusBar", 0));
        actionEditZoomIn->setText(QApplication::translate("SignalTap", "Zoom In", 0));
        actionEditZoomOut->setText(QApplication::translate("SignalTap", "Zoom Out", 0));
        actionViewAutoMensure->setText(QApplication::translate("SignalTap", "Auto Measure Window", 0));
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
