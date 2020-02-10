TEMPLATE = app
TARGET = QTProject

QT = core gui multimedia multimediawidgets
Qt += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

SOURCES += \
    ../Logger/intermediary_queue.cpp \
    ../Logger/Logger.cpp \
    ../Logger/log_buffer.cpp \
    ../RF-UI-Interface/connector.cpp \
    gui_test.cc \
    GuiWindow.cpp

HEADERS += \
    ../Logger/intermediary_queue.h \
    ../Logger/Loggable.h \
    ../Logger/Logger.h \
    ../Logger/log_buffer.h \
    ../RF-UI-Interface/ProtocolDefine.h \
    ../RF-UI-Interface/connector.h \
    ../Telecom/DataStructures/File/FileTransmissionStates.h \
    ui_form.h \
    GuiWindow.h

FORMS +=

RESOURCES += \
    assets.qrc
