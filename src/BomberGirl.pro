#-------------------------------------------------
#
# Project created by QtCreator 2014-04-10T10:47:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BomberGirl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    playground.cpp \
    player.cpp \
    field.cpp \
    wall.cpp \
    ground.cpp \
    fieldcontent.cpp \
    brick.cpp \
    elapsing.cpp \
    item.cpp \
    bomb.cpp \
    fire.cpp \
    flashitem.cpp \
    bombitem.cpp \
    corefire.cpp \
    extensionfire.cpp \
    endfire.cpp

HEADERS  += mainwindow.h \
    playground.h \
    player.h \
    field.h \
    wall.h \
    ground.h \
    fieldcontent.h \
    brick.h \
    elapsing.h \
    item.h \
    bomb.h \
    fire.h \
    flashitem.h \
    bombitem.h \
    corefire.h \
    extensionfire.h \
    endfire.h

FORMS    += mainwindow.ui

RESOURCES += \
    ../ressources.qrc
