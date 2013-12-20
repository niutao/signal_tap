#include "UsbDetector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/types.h>
#include <linux/netlink.h>
#include <errno.h>
#include <unistd.h>

#include <QtCore>

#define UEVENT_BUFFER_SIZE      2048

enum udev_monitor_netlink_group {
    UDEV_MONITOR_NONE,
    UDEV_MONITOR_KERNEL,
    UDEV_MONITOR_UDEV
};
UsbDetector::UsbDetector(QObject *parent):
    QObject(parent)
{
    mNetLinkSocket = -1;
    mSocketNotifier = NULL;
}

UsbDetector::~UsbDetector()
{
    stopDetector();
    close(mNetLinkSocket);
    mNetLinkSocket = -1;
}
/**
 * Create new udev monitor and connect to a specified event
 * source. Valid sources identifiers are "udev" and "kernel".
 *
 * Applications should usually not connect directly to the
 * "kernel" events, because the devices might not be useable
 * at that time, before udev has configured them, and created
 * device nodes.
 *
 * Accessing devices at the same time as udev, might result
 * in unpredictable behavior.
 *
 * The "udev" events are sent out after udev has finished its
 * event processing, all rules have been processed, and needed
 * device nodes are created.
 **/
bool UsbDetector::init()
{
    struct sockaddr_nl snl;
    const int buffersize = 16 * 1024 * 1024;
    int retval;

    memset(&snl, 0x00, sizeof(struct sockaddr_nl));
    snl.nl_family = AF_NETLINK;
    snl.nl_pid = getpid();
    snl.nl_groups = UDEV_MONITOR_KERNEL;

    mNetLinkSocket = socket(PF_NETLINK, SOCK_DGRAM, NETLINK_KOBJECT_UEVENT);
    if (mNetLinkSocket == -1) {
        qWarning("error getting socket: %s", strerror(errno));
        return false;
    }

    /* set receive buffersize */
    setsockopt(mNetLinkSocket, SOL_SOCKET, SO_RCVBUFFORCE, &buffersize, sizeof(buffersize));
    retval = bind(mNetLinkSocket, (struct sockaddr *)&snl, sizeof(struct sockaddr_nl));
    if (retval < 0) {
        qWarning("bind failed: %s", strerror(errno));
        close(mNetLinkSocket);
        mNetLinkSocket = -1;
        return false;
    } else if (retval == 0) {
        //from libudev-monitor.c
        struct sockaddr_nl _snl;
        socklen_t _addrlen;

        /*
         * get the address the kernel has assigned us
         * it is usually, but not necessarily the pid
         */
        _addrlen = sizeof(struct sockaddr_nl);
        retval = getsockname(mNetLinkSocket, (struct sockaddr *)&_snl, &_addrlen);
        if (retval == 0)
            snl.nl_pid = _snl.nl_pid;
    }

    mSocketNotifier = new QSocketNotifier(mNetLinkSocket, QSocketNotifier::Read, this);
    connect(mSocketNotifier, SIGNAL(activated(int)), SLOT(parseDeviceInfo()));
    mSocketNotifier->setEnabled(false);

    return true;
}
bool UsbDetector::startDetector()
{
    if (!init())
        return false;

    mSocketNotifier->setEnabled(true);

    return true;
}

bool UsbDetector::stopDetector()
{
    if (mNetLinkSocket != -1) {

        mSocketNotifier->setEnabled(false);

        close(mNetLinkSocket);
        mNetLinkSocket = -1;
    }
    return true;
}

void UsbDetector::usbDetectorCallback()
{
    QByteArray data;

    data.resize(UEVENT_BUFFER_SIZE * 2);
    data.fill(0);
    size_t len = read(mSocketNotifier->socket(), data.data(), UEVENT_BUFFER_SIZE * 2);
    qDebug("read fro socket %d bytes", len);
    data.resize(len);

    //In the original line each information is seperated by 0
    data = data.replace(0, '\n').trimmed();

    if (mSocketBuffer.isOpen())
        mSocketBuffer.close();

    mSocketBuffer.setBuffer(&data);
    mSocketBuffer.open(QIODevice::ReadOnly);

    while (!mSocketBuffer.atEnd()) {
        parseLine(mSocketBuffer.readLine().trimmed());
    }

    mSocketBuffer.close();
}

void UsbDetector::parseLine(const QByteArray & line)
{
    qDebug("%s", line.constData());

    if (!line.contains("/block/"))    //hotplug
        return;

    QString action_str = line.left(line.indexOf('@')).toLower();
    QString dev = "/dev/" + line.right(line.length() - line.lastIndexOf('/') - 1);

    if (action_str == QLatin1String("add")) {
        deviceAdded(dev);
    } else if (action_str == QLatin1String("remove")) {
        deviceRemoved(dev);
    } else if (action_str == QLatin1String("change")) {
        deviceChanged(dev);
    }

    qDebug("NIUTAOACTION = %s\n", qPrintable(action_str));
    qDebug("NIUTAODEV = %s\n",qPrintable(dev));
}
