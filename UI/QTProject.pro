TEMPLATE = app
TARGET = QTProject

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    ../RF-UI-Interface/connector.cpp \
    gui_test.cc \
    GuiWindow.cpp

HEADERS += \
    ../RF-UI-Interface/ProtocolDefine.h \
    ../RF-UI-Interface/connector.h \
    ui_form.h \
    GuiWindow.h

FORMS +=
