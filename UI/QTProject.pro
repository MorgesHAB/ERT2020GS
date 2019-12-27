TEMPLATE = app
TARGET = QTProject

QT = core gui
Qt += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

SOURCES += \
    ../Logger/intermediary_queue.cpp \
    ../Logger/logger.cpp \
    ../RF-UI-Interface/connector.cpp \
    gui_test.cc \
    GuiWindow.cpp

HEADERS += \
    ../Logger/intermediary_queue.h \
    ../Logger/loggable.h \
    ../Logger/logger.h \
    ../RF-UI-Interface/ProtocolDefine.h \
    ../RF-UI-Interface/connector.h \
    ui_form.h \
    GuiWindow.h

FORMS +=

RESOURCES += \
    asstes.qrc
