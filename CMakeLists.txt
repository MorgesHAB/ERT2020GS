cmake_minimum_required(VERSION 3.6.2)
project(BELLA_LUI_GS_SOFTWARE)

set(CMAKE_CXX_STANDARD 14)

#file(GLOB_RECURSE source_files src/GPS.* src/Packet.* src/GST.cpp)
link_directories(lib)
file(GLOB_RECURSE source_files src/*
        lib/RH_RF95.cpp lib/RHGenericSPI.cpp lib/RHLinuxSPI.cpp lib/RHGenericDriver.cpp)

add_executable(${PROJECT_NAME} ${source_files})

# On RPi : sudo apt-get install cmake