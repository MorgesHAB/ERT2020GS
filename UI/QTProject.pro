TEMPLATE = app
TARGET = QTProject

QT = core gui multimediawidgets multimedia
Qt += multimedia
CONFIG+=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

SOURCES += \
    ../Logger/double_buffer.cpp \
    ../Logger/Logger.cpp \
    ../Logger/Logger_buffer.cpp \
    ../RF-UI-Interface/connector.cpp \
    gui_test.cc \
    GuiWindow.cpp \
    logger_tests.cc

HEADERS += \
    ../Logger/double_buffer.h \
    ../Logger/Loggable.h \
    ../Logger/Logger.h \
    ../Logger/Logger_buffer.h \
    ../RF-UI-Interface/ProtocolDefine.h \
    ../RF-UI-Interface/connector.h \
    ../Telecom/DataStructures/File/FileTransmissionStates.h \
    ui_form.h \
    GuiWindow.h

FORMS +=

RESOURCES += \
    assets.qrc
