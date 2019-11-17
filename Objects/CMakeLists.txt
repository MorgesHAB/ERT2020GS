cmake_minimum_required(VERSION 3.6.2)
project(Objects)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SOURCES "*.cpp")

add_library(${PROJECT_NAME} ${SOURCES})

#target_include_directories(${PROJECT_NAME} PUBLIC Objects/DataStructures)
#target_include_directories(${PROJECT_NAME} PUBLIC Objects/RFmodem)
#target_include_directories(${PROJECT_NAME} PUBLIC Objects/Serializer)

