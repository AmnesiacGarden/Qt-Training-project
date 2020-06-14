#-------------------------------------------------
#
# Project created by QtCreator 2020-05-24T13:41:40
#
#-------------------------------------------------

QT       += core gui
#QT += core
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QQ
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        qqwidget.cpp \
    reg.cpp \
    er.cpp \
    chat.cpp \
    windows.cpp \
    chekuw.cpp \
    dixiashiw.cpp \
    waijingw.cpp \
    waidamenw.cpp \
    woshiw.cpp \
    chufangw.cpp

HEADERS += \
        qqwidget.h \
    reg.h \
    er.h \
    chat.h \
    proto.h \
    windows.h \
    chekuw.h \
    dixiashiw.h \
    waijingw.h \
    waidamenw.h \
    woshiw.h \
    chufangw.h

FORMS += \
        qqwidget.ui \
    reg.ui \
    er.ui \
    chat.ui \
    mianwindows.ui \
    windows.ui \
    chekuw.ui \
    dixiashiw.ui \
    waijingw.ui \
    waidamenw.ui \
    woshiw.ui \
    chufangw.ui

RESOURCES += \
    img/img.qrc \
    images/imgs.qrc \
    mianwindows.qrc
