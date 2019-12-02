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
    add_subdirectory(UI)
    add_executable(${PROJECT_NAME} src/GUI.cpp)
endif (USE_GUI)

if (USE_LORA)
    add_executable(GSE src/GSE.cpp)
    add_executable(GST src/GST.cpp)
    add_executable(TxRx src/TxRx.cpp)
endif (USE_LORA)

if (USE_XBEE)
    add_executable(XbeeTest src/XbeeTest.cpp)
endif (USE_XBEE)

if (USE_LORA)
    target_link_libraries(GSE Telecom)
    target_link_libraries(GST Telecom)
    target_link_libraries(TxRx Telecom)
endif (USE_LORA)

if (USE_XBEE)
    include_directories(${CMAKE_BINARY_DIR}/serial-src/include/)
    target_link_libraries(XbeeTest Telecom)
endif (USE_XBEE)

if (USE_GUI)
    target_link_libraries(${PROJECT_NAME} GUI)
endif (USE_GUI)
