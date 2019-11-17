cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/RadioHead)
add_subdirectory(lib/serial)
add_subdirectory(Objects)

add_executable(${PROJECT_NAME} src/GSE.cpp)
#add_executable(${PROJECT_NAME} src/GST.cpp)

target_link_libraries(${PROJECT_NAME} Objects)

target_link_libraries(${PROJECT_NAME} gps) #GPS
target_link_libraries(${PROJECT_NAME} RadioHead) #LoRa
# Xbee serial
include_directories(${CMAKE_BINARY_DIR}/serial-src/include/)
target_link_libraries(${PROJECT_NAME} serial)
