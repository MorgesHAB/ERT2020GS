cmake_minimum_required(VERSION 3.6.2)
project(Telecom)

add_subdirectory(RFmodem/lib/RadioHead)
add_subdirectory(RFmodem/lib/serial)

file(GLOB SOURCES DataStructures/*.cpp RFmodem/*.cpp Serializer/*.cpp
                  DataHandler/*.cpp)

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC DataStructures)
target_include_directories(${PROJECT_NAME} PUBLIC RFmodem)
target_include_directories(${PROJECT_NAME} PUBLIC RFmodem/lib/RadioHead)
target_include_directories(${PROJECT_NAME} PUBLIC Serializer)
target_include_directories(${PROJECT_NAME} PUBLIC DataHandler)

target_link_libraries(${PROJECT_NAME} gps) # GPS
target_link_libraries(${PROJECT_NAME} RadioHead) # LoRa
# Xbee serial
include_directories(${CMAKE_BINARY_DIR}/serial-src/include/)
target_link_libraries(${PROJECT_NAME} serial)

