#-------------------------------------------------
#
# Project created by QtCreator 2019-12-08T12:37:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projet_hap
TEMPLATE = app

INCLUDEPATH += "C:\Program Files\Immersion Corporation\IFC23\inc"

LIBS += "C:\Program Files\Immersion Corporation\IFC23\lib\IFC23.lib"

SOURCES += main.cpp\
        mainwindow.cpp \
    mygraphicsscene1.cpp \
    mygraphicsscene2.cpp \
    cube.cpp \
    mygraphicsscene3.cpp \
    mygraphicsscene.cpp \
    gestionhaptique.cpp

HEADERS  += mainwindow.h \
    mygraphicsscene1.h \
    mygraphicsscene2.h \
    cube.h \
    mygraphicsscene3.h \
    mygraphicsscene.h \
    gestionhaptique.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
