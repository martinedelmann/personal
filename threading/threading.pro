#-------------------------------------------------
#
# Project created by QtCreator 2013-02-03T12:34:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = threading
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    work.cpp \
    downloader.cpp

HEADERS  += mainwindow.h \
    work.h \
    downloader.h

FORMS    += mainwindow.ui
