#-------------------------------------------------
#
# Project created by QtCreator 2020-05-29T10:14:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MotherFuckerTowerDefense
TEMPLATE = app

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
        main.cpp \
        mainwindow.cpp \
    button1.cpp \
    choose.cpp \
    hardlevel.cpp \
    easylevel.cpp \
    towerposition.cpp \
    tower.cpp \
    turnpoint.cpp \
    enemy.cpp \
    button2.cpp \
    rule.cpp

HEADERS += \
        mainwindow.h \
    button1.h \
    choose.h \
    hardlevel.h \
    easylevel.h \
    towerposition.h \
    tower.h \
    turnpoint.h \
    enemy.h \
    button2.h \
    rule.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    mode.qrc
