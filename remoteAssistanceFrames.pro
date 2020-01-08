QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = remoteAssistanceFrames
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    createverificationcodeframe.cpp \
    enterverificationcode.cpp \
    mainwindow.cpp \
    createverificationlabel.cpp \
    copyverificationsuccessframe.cpp \
    promptlabel.cpp \
    connectfaildframe.cpp \
    connectingframe.cpp \
    assistingframe.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    createverificationcodeframe.h \
    enterverificationcode.h \
    mainwindow.h \
    createverificationlabel.h \
    copyverificationsuccessframe.h \
    promptlabel.h \
    connectfaildframe.h \
    connectingframe.h \
    assistingframe.h
