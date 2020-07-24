QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport sql

SOURCES += \
    dialog.cpp \
    layoutDemo.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow2.cpp \
    mytcpsocket.cpp \
    qwidgetdemo.cpp \
    qwidgetdraw.cpp \
    qwidgetserialrx.cpp \
    qwidgetserialtx.cpp

HEADERS += \
    dialog.h \
    layoutDemo.h \
    mainwindow.h \
    mainwindow2.h \
    mytcpsocket.h \
    qwidgetdemo.h \
    qwidgetdraw.h \
    qwidgetserialrx.h \
    qwidgetserialtx.h

FORMS += \
    mainwindow.ui \
    mainwindow1.ui \
    mainwindow2.ui
