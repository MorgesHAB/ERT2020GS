cmake_minimum_required(VERSION 3.6.2)
project(RF-UI-Interface)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SOURCES "*.cpp")

add_library(${PROJECT_NAME} ${SOURCES} ProtocolDefine.h)
target_link_libraries(${PROJECT_NAME} atomic)


