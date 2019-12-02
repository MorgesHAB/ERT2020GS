TEMPLATE = app
TARGET = QTProject

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    ../RF-UI-Interface/connector.cpp \
    main.cc \
    gpswindow.cpp

HEADERS += \
    ../RF-UI-Interface/ProtocolDefine.h \
    ../RF-UI-Interface/connector.h \
    ui_form.h \
    gpswindow.h

FORMS +=
