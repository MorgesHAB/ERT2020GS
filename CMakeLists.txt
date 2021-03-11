cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

###############################################################
# Set the build varialble to ON or OFF on your need
set(USE_GUI ON)
set(USE_XBEE ON)
set(RUNNING_ON_RPI OFF) # <-- if not ON, the Ignition hardware won't wrork
set(USE_SOUND OFF)
####
set(USE_LORA OFF)
###############################################################
if (NOT RUNNING_ON_RPI)
    message("/!\\ Ignition Circuit not activated !")
endif ()

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Logger)
add_subdirectory(Telecom)
add_subdirectory(RF-UI-Interface)

if (USE_XBEE)
    include_directories(Telecom/RFmodem/lib/serial/include/)

    add_executable(AVsimulator src/AVsimulator.cpp)
    add_executable(GSE_PLsimu src/GSE_PLsimu.cpp)
    add_executable(TestPacket src/PacketXTest.cpp)

    if (USE_GUI)
        find_package(Qt5Widgets)
        find_package(Qt5Charts)
        qt5_add_resources(RCC_SOURCES UI/assets.qrc)      # add resources to Gui
        add_subdirectory(UI)
        add_executable(${PROJECT_NAME} ${RCC_SOURCES} src/ERT2020GS.cpp)
    endif (USE_GUI)

endif (USE_XBEE)

############# link librarie to targets #######################
if (USE_XBEE)
    target_link_libraries(AVsimulator Telecom)
    target_link_libraries(GSE_PLsimu Telecom)
    target_link_libraries(TestPacket Telecom)

    add_executable(XbeeTest src/XbeeTest.cpp)
    include_directories(RFmodem/lib/serial/include/)
    target_link_libraries(XbeeTest serial)

    if (USE_GUI)
        target_link_libraries(${PROJECT_NAME} GUI)
        target_include_directories(${PROJECT_NAME} PUBLIC UI)
    endif (USE_GUI)

endif (USE_XBEE)
