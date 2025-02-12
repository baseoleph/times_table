# Times Table
# Copyright (C) 2021 baseoleph@gmail.com

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mqgraphicsview.cpp \
    scene.cpp

HEADERS += \
    mainwindow.h \
    mqgraphicsview.h \
    scene.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
