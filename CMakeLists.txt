cmake_minimum_required(VERSION 3.6.2)
project(BELLA_LUI_GS_SOFTWARE)

set(CMAKE_CXX_STANDARD 14)

#file(GLOB_RECURSE source_files src/GPS.* src/Packet.* src/GST.cpp)
set (CMAKE_CXX_FLAGS "-g -Wall -DRH_PLATFORM=RH_PLATFORM_RPI -D__RASPBERRY_PI_ -lwiringPi")
link_directories(lib)
file(GLOB_RECURSE source_files src/*
        lib/RH_RF95.cpp lib/RHGenericSPI.cpp lib/RHLinuxSPI.cpp lib/RHGenericDriver.cpp)

add_executable(${PROJECT_NAME} ${source_files})

# On RPi : sudo apt-get install cmake