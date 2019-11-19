cmake_minimum_required(VERSION 3.6.2)
project(RadioHead)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SOURCES RH_RF95.cpp RHGenericSPI.cpp
                          RHLinuxSPI.cpp RHGenericDriver.cpp)

add_library(${PROJECT_NAME} ${SOURCES})

target_compile_options(${PROJECT_NAME} PUBLIC -g -Wall
                       -DRH_PLATFORM=RH_PLATFORM_RPI -D__RASPBERRY_PI_)

target_link_libraries(${PROJECT_NAME} wiringPi)