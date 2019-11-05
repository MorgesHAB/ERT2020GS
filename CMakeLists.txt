cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

set(CMAKE_CXX_STANDARD 11)

#file(GLOB_RECURSE source_files src/GPS.* src/Packet.* src/GST.cpp)
set (CMAKE_CXX_FLAGS "-g -Wall -DRH_PLATFORM=RH_PLATFORM_RPI -D__RASPBERRY_PI_")
set (CMAKE_EXE_LINKER_FLAGS_INIT "-lwiringPi")
link_directories(lib)
file(GLOB_RECURSE source_files src/*)

add_executable(${PROJECT_NAME} ${source_files})

# On RPi : sudo apt-get install cmake