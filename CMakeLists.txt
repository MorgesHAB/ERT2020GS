cmake_minimum_required(VERSION 3.15)
project(Packet)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE source_files src/*.cpp src/*.h)

add_executable(${PROJECT_NAME} ${source_files})