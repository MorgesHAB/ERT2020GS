cmake_minimum_required(VERSION 3.6.2)
project(Packet)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE source_files src/GPS.* src/Packet.* main.cpp)

add_executable(${PROJECT_NAME} ${source_files})

# On RPi : sudo apt-get install cmake