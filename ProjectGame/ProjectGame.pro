#-------------------------------------------------
#
# Project created by QtCreator 2016-10-12T17:50:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjectGame
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    main.cpp \
    room.cpp

HEADERS  += mainwindow.h \
    playgame.h \
    room.h

FORMS    += mainwindow.ui

RESOURCES += \
    ship.qrc
