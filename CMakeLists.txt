cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

###############################################################
# Set the build varialble to ON or OFF on your need
set(USE_GUI ON)
set(USE_LORA OFF)
set(USE_XBEE ON)
set(USE_GPS OFF)
###############################################################
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Telecom)
add_subdirectory(RF-UI-Interface)

if (USE_GUI)
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
    qt5_add_resources(RCC_SOURCES UI/logo.qrc)      # add image to Gui
    add_subdirectory(UI)
    add_executable(${PROJECT_NAME} ${RCC_SOURCES} src/GUI.cpp)
endif (USE_GUI)

if (USE_LORA)
    add_executable(LoRaTest src/LoRaTest.cpp)
endif (USE_LORA)

if (USE_XBEE)
    add_executable(XbeeTest src/XbeeTest.cpp)
    add_executable(IgniterRPi src/IgniterRPi.cpp)
    target_link_libraries(IgniterRPi ${INDI_DRIVER_LIBRARIES} ${WIRING_PI_LIBRARIES} crypt)
endif (USE_XBEE)

if (USE_LORA)
    target_link_libraries(LoRaTest Telecom)
endif (USE_LORA)

if (USE_XBEE)
    include_directories(Telecom/RFmodem/lib/serial/include/)
    target_link_libraries(XbeeTest Telecom)
    target_link_libraries(IgniterRPi Telecom)
    target_link_libraries(XbeeTest wiringPi) # control GPIO of RPi
    target_link_libraries(IgniterRPi wiringPi) # control GPIO of RPi
    
endif (USE_XBEE)

if (USE_GUI)
    include_directories(Telecom/RFmodem/lib/serial/include/)
    target_link_libraries(${PROJECT_NAME} GUI)
    target_include_directories(${PROJECT_NAME} PUBLIC UI)
endif (USE_GUI)
