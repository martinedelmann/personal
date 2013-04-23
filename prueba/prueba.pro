#-------------------------------------------------
#
# Project created by QtCreator 2013-02-02T21:31:05
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prueba
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    downloadmanager.cpp \
    download.cpp \
    parsermanager.cpp \
    parser.cpp \
    subitem.cpp

HEADERS  += mainwindow.h \
    downloadmanager.h \
    download.h \
    parsermanager.h \
    parser.h \
    subitem.h

FORMS    += mainwindow.ui
