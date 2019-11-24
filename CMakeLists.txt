cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

###############################################################
# Set the build varialble to ON or OFF on your need
set(USE_GUI OFF)
set(USE_LORA ON)
set(USE_XBEE ON)
###############################################################
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Telecom)
if (USE_GUI)
    add_subdirectory(UI)
    add_executable(${PROJECT_NAME} UI/main.cc)
endif (USE_GUI)

add_executable(GSE src/GSE.cpp)
add_executable(GST src/GST.cpp)
add_executable(TxRx src/TxRx.cpp)

target_link_libraries(GSE Telecom)
target_link_libraries(GST Telecom)
target_link_libraries(TxRx Telecom)
if (USE_GUI)
    target_link_libraries(${PROJECT_NAME} GUI)
endif (USE_GUI)