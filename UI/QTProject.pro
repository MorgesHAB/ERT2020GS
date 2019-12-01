TEMPLATE = app
TARGET = QTProject

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    connector.cpp \
    main.cc \
    gpswindow.cpp

HEADERS += \
    connector.h \
    ui_form.h \
    gpswindow.h

FORMS +=
