cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE SOURCES_LIB lib/RH_RF95.cpp lib/RHGenericSPI.cpp
                              lib/RHLinuxSPI.cpp lib/RHGenericDriver.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${SOURCES_LIB})
target_compile_options(${PROJECT_NAME} PUBLIC -g -Wall -DRH_PLATFORM=RH_PLATFORM_RPI -D__RASPBERRY_PI_)
target_include_directories(${PROJECT_NAME} PUBLIC lib/)
target_link_libraries(${PROJECT_NAME} wiringPi)
