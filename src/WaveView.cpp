#include "WaveView.h"
#include "SignalTap.h"
#include <errno.h>
#include "WaveTimeLine.h"
#include <QGraphicsItem>
#include <QScrollBar>
#include <QTabBar>
#include "WaveShow.h"
#include "UsbManager.h"
#include "UsbHandler.h"

WaveView::WaveView(SignalTap *st, QString *waveName):
    QGraphicsView(st)
{
    mST = st;
    setupUi();
    retranslateUi();

    mWidth = this->width();
    mHeight = this->height();
    mWaveName = waveName;
    mUsbHander = new UsbHandler();

    connect(mCloseButton, SIGNAL(clicked()), this, SLOT(onCloseButtonClicked()));
}

WaveView::~WaveView()
{
    desetupUi();
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
    mWaveShow->drawTest();
    horizontalScrollBar()->setSliderPosition(0);

    return true;
}

void WaveView::deviceAdded(UsbDeviceInfo *usb)
{
    mDevices->addItem(usb->mName);
    qDebug("add %s", qPrintable(usb->mName));
}

void WaveView::deviceRemoved(UsbDeviceInfo *usb)
{
    UsbDeviceInfo *info = mST->mUsbManager->findDevice(mDevices->currentText());
    if (info)
        qDebug("0x%x, 0x%x", info->mIdVendor, info->mIdProduct);
    mDevices->removeItem(mDevices->findText(usb->mName));

    qDebug("remove %s", qPrintable(usb->mName));
}

void WaveView::startCapture()
{

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
