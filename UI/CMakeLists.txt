##########################################
### CMakeLists for Ground Station Code with
### Graphical User Interface
##########################################
cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR  ON) # Qt
set(CMAKE_AUTOMOC ON)  # Qt
set(CMAKE_AUTORCC ON)  # Qt
#set(CMAKE_AUTOUIC ON)  # Qt

add_subdirectory(Telecom)

find_package(Qt5Widgets)

file(GLOB_RECURSE SOURCES ".cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} Telecom)


