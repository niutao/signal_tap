#include "WaveView.h"
#include "SignalTap.h"
#include <errno.h>
#include "WaveTimeLine.h"
#include <QGraphicsItem>
#include <QScrollBar>
#include <QMessageBox>
#include <QTabBar>
#include "WaveShow.h"
#include "UsbManager.h"
#include "UsbHandler.h"
#include "MenuBar.h"
#include "MenuCapture.h"
#include "st_usb.h"
#define DEFAULT_DEVICE "None"

void WaveView::init(SignalTap *st)
{
    mST = st;
    setupUi();
    retranslateUi();

    mWidth = this->width();
    mHeight = this->height();
    mUsbHandler = new UsbHandler();

    connect(mCloseButton, SIGNAL(clicked()), this, SLOT(onCloseButtonClicked()));
    connect(mUsbHandler, SIGNAL(dataValid()), this, SLOT(dataValid()));
    connect(mUsbHandler, SIGNAL(deviceInValid()), this, SLOT(deviceInValid()));
    connect(mUsbHandler, SIGNAL(dataError()), this, SLOT(dataError()));
    connect(mUsbHandler, SIGNAL(errorFound(int)), this, SLOT(errorFound(int)));
    connect(mUsbHandler, SIGNAL(dataSaved()), this, SLOT(dataSaved()));

    mDevices->addItem(DEFAULT_DEVICE);
    mDevices->setCurrentIndex(0);
}

WaveView::WaveView(SignalTap *st):
    QGraphicsView(st)
{
    mWaveName = new QString();
    init(st);
}
WaveView::WaveView(SignalTap *st, QString waveName):
    QGraphicsView(st)
{
    mWaveName = new QString(waveName);
    init(st);
}

WaveView::~WaveView()
{
    desetupUi();
    delete mWaveName;
}

void WaveView::setupUi()
{
    QVBoxLayout *leftVL;

    mTab = new WaveTabWidget(this);

    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(mTab->sizePolicy().hasHeightForWidth());
    mTab->setSizePolicy(sizePolicy1);

    mHL = new QHBoxLayout(mTab);
    mHL->setSpacing(2);
    mHL->setContentsMargins(0, 0, 0, 0);

    leftVL = new QVBoxLayout();
    leftVL->setSpacing(2);

    mDevices = new QComboBox();
    QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(mDevices->sizePolicy().hasHeightForWidth());
    mDevices->setSizePolicy(sizePolicy3);
    mDevices->setMinimumSize(QSize(100, 0));
    leftVL->addWidget(mDevices);

    mSignalView = new QListView(mTab);
    mSignalView->setEnabled(true);
    QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(mSignalView->sizePolicy().hasHeightForWidth());
    mSignalView->setSizePolicy(sizePolicy2);
    mSignalView->setMaximumSize(QSize(100, 16777215));
    mSignalView->setBaseSize(QSize(0, 0));

    leftVL->addWidget(mSignalView);
    mHL->addLayout(leftVL);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //waveView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QBrush brush(QColor(0, 0, 0, 255));
    brush.setStyle(Qt::NoBrush);
    setBackgroundBrush(brush);

    mWaveShow = new WaveShow(this);
    setScene(mWaveShow);


    mHL->addWidget(this);
    qDebug("mHL(%d, %d)\n", this->width(), this->height());

    QIcon icon;
    icon.addFile(QStringLiteral(":/res/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
    mCloseButton = new QPushButton();
    mCloseButton->setIcon(icon);
    mCloseButton->setFixedSize(24, 24);
    mCloseButton->setFocusPolicy(Qt::NoFocus);
    mCloseButton->setFlat(true);
}

void WaveView::desetupUi()
{
    delete mWaveShow;
#if 0
    // beacuse the mSignalView and mHL are add to the widget
    // SignalTap->mTopTab, so when we free the mTopTab, the
    // system will free these three widget automatic
    delete mSignalView;
    delete mHL;
    delete mTab;
#endif
}
void WaveView::retranslateUi()
{

}

int WaveView::getWidth()
{
    return mWidth;
}

int WaveView::getHeight()
{
    return mHeight;
}

void WaveView::resizeEvent(QResizeEvent *event)
{
    QSize s = event->size();
    Q_UNUSED(s);

    QRectF rect;

    QGraphicsScene *scene = this->scene();

    scene->setSceneRect(0, 0, scene->width(), event->size().height());

    mWidth = s.width();
    mHeight = s.height();

    rect.setX(0);
    rect.setY(0);
    rect.setWidth(scene->width());
    rect.setHeight(event->size().height());

    emit onSceneRectChangedEvent(rect);

    qDebug("size(%f, %f)\n", scene->width(), scene->height());
}

void WaveView::onCloseButtonClicked()
{
    mST->removeWaveView(this);
    this->disconnect();
    delete this;
}

bool WaveView::openWave(QString &wave)
{
    //mWaveShow->drawTest();
    horizontalScrollBar()->setSliderPosition(0);

    return true;
}
void WaveView::addDeviceList(QList <UsbDeviceInfo *> devices)
{
    foreach (UsbDeviceInfo *device, devices) {
        mDevices->addItem(device->mName);
    }
}

void WaveView::deviceAdded(UsbDeviceInfo *usb)
{
    mDevices->addItem(usb->mName);
    qDebug("add %s", qPrintable(usb->mName));
}

void WaveView::deviceRemoved(UsbDeviceInfo *usb)
{
    mDevices->removeItem(mDevices->findText(usb->mName));

    qDebug("remove %s", qPrintable(usb->mName));
}

void WaveView::startCapture()
{
    UsbDeviceInfo *device = mST->mUsbManager->findDevice(mDevices->currentText());
    if (!device) {
        QMessageBox message(QMessageBox::Warning,
                            "Error",
                            "No device found!",
                            QMessageBox::Yes, this);
        message.exec();
        return;
    }

    int ret = mUsbHandler->openDevice(device->mIdVendor, device->mIdProduct);
    if (ret != 0) {
        QMessageBox message(QMessageBox::Information,
                            "Information",
                            strerror(-ret),
                            QMessageBox::Yes, this);
        message.exec();
        return;
    }
    mUsbHandler->setSavedName(mWaveName);
    mUsbHandler->setReadEndPoint(0x86);
    mUsbHandler->setState(UsbHandler::READING);
    mUsbHandler->sendCtlMsg(ST_CMD_START_CAP, 0x0, NULL, 0, USB_CTRL_GET_TIMEOUT);
    mUsbHandler->start();
    mST->mMenuBar->mMenuCapture->setMenuEnable(MenuCapture::Start, false);
    mST->mMenuBar->mMenuCapture->setMenuEnable(MenuCapture::Stop, true);
}

void WaveView::stopCapture()
{
    mUsbHandler->sendCtlMsg(ST_CMD_STOP_CAP, 0x0, NULL, 0, USB_CTRL_SET_TIMEOUT);
    mUsbHandler->setState(UsbHandler::STOPREADING);
    mST->mMenuBar->mMenuCapture->setMenuEnable(MenuCapture::Start, true);
    mST->mMenuBar->mMenuCapture->setMenuEnable(MenuCapture::Stop, false);
}

void WaveView::dataValid()
{
    qDebug("dataValid");
}


void WaveView::deviceInValid()
{
    qDebug("deviceInValid");
}


void WaveView::dataError()
{
    qDebug("dataError");
}


void WaveView::errorFound(int error)
{
    qDebug("errorFound");
}


void WaveView::dataSaved()
{
    qDebug("dataSaved");
}



WaveTabWidget::WaveTabWidget(WaveView *waveview)
{
    mWaveView = waveview;
}
WaveTabWidget::~WaveTabWidget()
{
}
WaveView *WaveTabWidget::getWaveView()
{
    return mWaveView;
}
