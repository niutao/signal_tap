#-------------------------------------------------
#
# Project created by QtCreator 2013-12-08T15:42:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = signal_tap
TEMPLATE = app


SOURCES += \
    src/main.cpp\
    src/MenuEdit.cpp \
    src/MenuFile.cpp \
    src/WaveView.cpp \
    src/WaveTimeLine.cpp \
    src/GraphicsView.cpp \
    src/MenuView.cpp \
    src/MenuReplay.cpp \
    src/MenuHelp.cpp \
    src/MenuCapture.cpp \
    src/MenuBar.cpp \
    src/ToolBar.cpp \
    src/StatusBar.cpp \
    src/SignalTap.cpp

HEADERS  += \
    src/MenuEdit.h \
    src/MenuFile.h \
    src/WaveView.h \
    src/WaveTimeLine.h \
    src/GraphicsView.h \
    src/MenuView.h \
    src/MenuReplay.h \
    src/MenuHelp.h \
    src/MenuCapture.h \
    src/MenuBar.h \
    src/ToolBar.h \
    src/StatusBar.h \
    src/SignalTap.h

FORMS    += signaltap.ui

RESOURCES += \
    signal_tap.qrc
