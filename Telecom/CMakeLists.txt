cmake_minimum_required(VERSION 3.6.2)
project(Telecom)

add_subdirectory(RFmodem/RadioHead)
add_subdirectory(RFmodem/serial)

file(GLOB_RECURSE SOURCES "*.cpp")

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC DataStructures)
target_include_directories(${PROJECT_NAME} PUBLIC RFmodem)
target_include_directories(${PROJECT_NAME} PUBLIC Serializer)

target_link_libraries(${PROJECT_NAME} gps) #GPS
target_link_libraries(${PROJECT_NAME} RadioHead) #LoRa
# Xbee serial
include_directories(${CMAKE_BINARY_DIR}/serial-src/include/)
target_link_libraries(${PROJECT_NAME} serial)

