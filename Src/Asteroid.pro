#-------------------------------------------------
#
# Project created by QtCreator 2018-02-19T12:11:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Asteroid
TEMPLATE = app
CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    game_manager.cpp \
    main.cpp \
    mainwindow.cpp \
    object.cpp \
    ship.cpp \
    state.cpp \
    testmodel.cpp \
    widget.cpp \
    objectpainter.cpp \
    objectbuilder.cpp \
    controller.cpp \
    bullet.cpp \
    gamescore.cpp \
    gtools.cpp

HEADERS += \
    game_manager.h \
    mainwindow.h \
    object.h \
    ship.h \
    state.h \
    testmodel.h \
    widget.h \
    objectpainter.h \
    objectbuilder.h \
    controller.h \
    bullet.h \
    gamescore.h \
    gtools.h

FORMS += \
        mainwindow.ui \
    widget.ui \
    gamescore.ui

DISTFILES +=

RESOURCES += \
    res.qrc
