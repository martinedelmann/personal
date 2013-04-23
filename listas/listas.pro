#-------------------------------------------------
#
# Project created by QtCreator 2013-02-06T20:34:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = listas
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    file.cpp \
    fileManager.cpp \
    ArchivoBufr.cpp \
    DatosRadar.cpp \
    Radar.cpp

HEADERS  += mainwindow.h \
    file.h \
    fileManager.h \
    defines.h \
    ArchivoBufr.h \
    DatosRadar.h \
    Radar.h \
    estructuras.h

FORMS    += mainwindow.ui
