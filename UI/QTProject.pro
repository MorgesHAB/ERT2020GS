TEMPLATE = app
TARGET = QTProject

QT = core gui multimediawidgets multimedia
Qt += multimedia
CONFIG+=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

SOURCES += \
    ../Logger/Double_buffer.cpp \
    ../Logger/Logger.cpp \
    ../Logger/Logger_buffer.cpp \
    ../RF-UI-Interface/connector.cpp \
    Gui_message.cpp \
    SecondWindow.cpp \
    gui_logger.cpp \
    gui_test.cc \
    GuiWindow.cpp \
    logger_tests.cc \
    ../Logger/utilities.cpp

HEADERS += \
    ../Logger/Double_buffer.h \
    ../Logger/Loggable.h \
    ../Logger/Logger.h \
    ../Logger/Logger_buffer.h \
    ../RF-UI-Interface/ProtocolDefine.h \
    ../RF-UI-Interface/connector.h \
    ../Telecom/DataHandler/DatagramTypes.h \
    ../Telecom/DataStructures/File/FileTransmissionStates.h \
    ../Telecom/DataStructures/GSE/IgnitionStates.h \
    Gui_message.h \
    SecondWindow.h \
    gui_logger.h \
    second_ui.h \
    ui_form.h \
    GuiWindow.h \
    ../Logger/utilities.h

FORMS +=

RESOURCES += \
    assets.qrc
