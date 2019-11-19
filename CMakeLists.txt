cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

set(CMAKE_CXX_STANDARD 11)

set(USE_GUI OFF)
set(USE_LORA ON)
set(USE_XBEE OFF)

add_subdirectory(Telecom)

add_executable(GSE src/GSE.cpp)
add_executable(GST src/GST.cpp)

target_link_libraries(GSE Telecom)
target_link_libraries(GST Telecom)
