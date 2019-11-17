cmake_minimum_required(VERSION 3.6.2)
project(RadioHead)

file(GLOB_RECURSE SOURCES_LIB RH_RF95.cpp RHGenericSPI.cpp
                              RHLinuxSPI.cpp RHGenericDriver.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
