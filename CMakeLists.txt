cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

set(CMAKE_CXX_STANDARD 11)

#file(GLOB_RECURSE source_files src/GPS.* src/Packet.* src/GST.cpp)
set (CMAKE_CXX_FLAGS "-g -Wall -DRH_PLATFORM=RH_PLATFORM_RPI -D__RASPBERRY_PI_")
set (CMAKE_EXE_LINKER_FLAGS_INIT "-lwiringPi")
#link_directories(lib)
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE SOURCES_LIB lib/RH_RF95.cpp lib/RHGenericSPI.cpp
                              lib/RHLinuxSPI.cpp lib/RHGenericDriver.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${SOURCES_LIB})
#add_library(RadioHeadLibrary STATIC ${SOURCES_LIB})
#target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${RadioHeadLibrary})