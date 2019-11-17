cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Telecom)

add_executable(${PROJECT_NAME} src/GSE.cpp)
#add_executable(${PROJECT_NAME} src/GST.cpp)

target_link_libraries(${PROJECT_NAME} Telecom)
