#-------------------------------------------------
#
# Project created by QtCreator 2014-05-17T21:38:53
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tank.cpp \
    missile.cpp \
    score.cpp \
    obstacle.cpp

HEADERS  += mainwindow.h \
    tank.h \
    missile.h \
    score.h \
    obstacle.h

FORMS    += mainwindow.ui
