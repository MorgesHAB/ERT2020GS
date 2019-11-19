cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

set(CMAKE_CXX_STANDARD 11)

set(USE_GUI OFF)
set(USE_LORA ON)
set(USE_XBEE ON)

add_subdirectory(Telecom)

add_executable(${PROJECT_NAME} src/GSE.cpp)
#add_executable(${PROJECT_NAME} src/GST.cpp)

target_link_libraries(${PROJECT_NAME} Telecom)
