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
        src/signaltap.cpp \
    src/MenuEdit.cpp \
    src/MenuFile.cpp

HEADERS  += \
	src/signaltap.h \
    src/MenuEdit.h \
    src/MenuFile.h \
    Debug/ui_signaltap.h

FORMS    += signaltap.ui

RESOURCES += \
    signal_tap.qrc
