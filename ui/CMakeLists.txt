##########################################
### CMakeLists for Ground Station Code with
### Graphical User Interface
##########################################
cmake_minimum_required(VERSION 3.6.2)
project(ERT2020GS)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR  ON) # Qt
set(CMAKE_AUTOMOC ON)  # Qt
set(CMAKE_AUTORCC ON)  # Qt
#set(CMAKE_AUTOUIC ON)  # Qt

find_package(Qt5Widgets)

# Add your file here ---->|
file(GLOB_RECURSE QtSOURCES main.cpp gpswindow.cpp)

file(GLOB_RECURSE SOURCES ../Objects/*.cpp)
file(GLOB_RECURSE SOURCES_LIB ../lib/RH_RF95.cpp ../lib/RHGenericSPI.cpp
        ../lib/RHLinuxSPI.cpp ../lib/RHGenericDriver.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${SOURCES_LIB} ${QtSOURCES})
target_compile_options(${PROJECT_NAME} PUBLIC -g -Wall -DRH_PLATFORM=RH_PLATFORM_RPI -D__RASPBERRY_PI_)

target_include_directories(${PROJECT_NAME} PUBLIC ../lib)
target_include_directories(${PROJECT_NAME} PUBLIC ../Objects/DataStructures)
target_include_directories(${PROJECT_NAME} PUBLIC ../Objects/RFmodem)
target_include_directories(${PROJECT_NAME} PUBLIC ../Objects/Serializer)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} wiringPi) # LoRa
target_link_libraries(${PROJECT_NAME} gps) #GPS

