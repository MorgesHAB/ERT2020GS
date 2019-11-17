cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCES Objects/*.cpp)
file(GLOB_RECURSE SOURCES_LIB lib/RadioHead/RH_RF95.cpp lib/RadioHead/RHGenericSPI.cpp
     lib/RadioHead/RHLinuxSPI.cpp lib/RadioHead/RHGenericDriver.cpp)

add_subdirectory(lib/serial)

add_executable(${PROJECT_NAME} ${SOURCES} ${SOURCES_LIB} src/GSE.cpp)
#add_executable(${PROJECT_NAME} ${SOURCES} ${SOURCES_LIB} src/GST.cpp)
target_compile_options(${PROJECT_NAME} PUBLIC -g -Wall -DRH_PLATFORM=RH_PLATFORM_RPI -D__RASPBERRY_PI_)

target_include_directories(${PROJECT_NAME} PUBLIC lib/RadioHead)
target_include_directories(${PROJECT_NAME} PUBLIC Objects/DataStructures)
target_include_directories(${PROJECT_NAME} PUBLIC Objects/RFmodem)
target_include_directories(${PROJECT_NAME} PUBLIC Objects/Serializer)

target_link_libraries(${PROJECT_NAME} wiringPi) # LoRa
target_link_libraries(${PROJECT_NAME} gps) #GPS

# Xbee serial
include_directories(${CMAKE_BINARY_DIR}/serial-src/include/)
target_link_libraries(${PROJECT_NAME} serial)
