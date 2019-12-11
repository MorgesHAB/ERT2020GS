cmake_minimum_required(VERSION 3.6.2)
project(GUI)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets)

file(GLOB SOURCES "*.cpp")

add_library(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} Telecom)
add_executable(gui gui_test.cc)



