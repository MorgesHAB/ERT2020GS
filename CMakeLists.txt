cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

set(CMAKE_CXX_STANDARD 11)

set(USE_GUI OFF)
set(USE_LORA ON)
set(USE_XBEE OFF)

add_subdirectory(Telecom)
if (USE_GUI)
    add_subdirectory(UI)
    add_executable(${PROJECT_NAME} UI/main.cc)
endif (USE_GUI)

add_executable(GSE src/GSE.cpp)
add_executable(GST src/GST.cpp)
add_executable(T src/TxRx.cpp)
add_executable(T2 src/TxRx2.cpp)

target_link_libraries(GSE Telecom)
target_link_libraries(GST Telecom)
target_link_libraries(T Telecom)
target_link_libraries(T2 Telecom)
if (USE_GUI)
    target_link_libraries(${PROJECT_NAME} GUI)
endif (USE_GUI)