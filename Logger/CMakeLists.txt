cmake_minimum_required(VERSION 3.6.2)
project(LogLib)

file(GLOB_RECURSE SOURCES "*.cpp" "*.h")

add_library(${PROJECT_NAME} ${SOURCES})