cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

###############################################################
# Set the build varialble to ON or OFF on your need
set(USE_GUI ON)
set(USE_XBEE ON)
set(USE_LORA OFF)
set(USE_GPS OFF)
###############################################################
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Telecom)
add_subdirectory(RF-UI-Interface)

if (USE_LORA)
    add_executable(LoRaTest src/LoRaTest.cpp)
endif (USE_LORA)

if (USE_XBEE)
    include_directories(Telecom/RFmodem/lib/serial/include/)
    add_executable(XbeeTest src/XbeeTest.cpp)
    add_executable(IgniterRPi src/IgniterRPi.cpp)

    if (USE_GUI)
        find_package(Qt5Widgets)
        qt5_add_resources(RCC_SOURCES UI/logo.qrc)      # add image to Gui
        add_subdirectory(UI)
        add_executable(${PROJECT_NAME} ${RCC_SOURCES} src/GUI.cpp)
    endif (USE_GUI)

endif (USE_XBEE)

############# link librarie to targets #######################

if (USE_LORA)
    target_link_libraries(LoRaTest Telecom)
endif (USE_LORA)

if (USE_XBEE)
    target_link_libraries(XbeeTest Telecom)
    target_link_libraries(IgniterRPi Telecom)

    if (USE_GUI)
        target_link_libraries(${PROJECT_NAME} GUI)
        target_include_directories(${PROJECT_NAME} PUBLIC UI)
    endif (USE_GUI)

endif (USE_XBEE)
