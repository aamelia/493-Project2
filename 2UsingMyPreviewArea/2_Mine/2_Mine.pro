#-------------------------------------------------
#
# Project created by QtCreator 2013-03-23T20:35:58
#
#-------------------------------------------------

QT       += core gui xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2_Mine
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fimage.cpp \
    flickrcollector.cpp \
    imagecollector.cpp \
    previewarea.cpp \
    deleteimagecommand.cpp

HEADERS  += mainwindow.h \
    fimage.h \
    flickrcollector.h \
    imagecollector.h \
    previewarea.h \
    deleteimagecommand.h
