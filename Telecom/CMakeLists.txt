cmake_minimum_required(VERSION 3.6.2)
project(Telecom)

if (RUNNING_ON_RPI)
    add_definitions(-DRUNNING_ON_RPI)
endif (RUNNING_ON_RPI)


if (USE_LORA)
    add_subdirectory(RFmodem/lib/RadioHead)
    file(GLOB SOURCES_RF RFmodem/LoRa.cpp)
endif (USE_LORA)
if (USE_XBEE)
    add_subdirectory(RFmodem/lib/serial)
    file(GLOB SOURCES_RF2 RFmodem/Xbee.cpp)
endif (USE_XBEE)

file(GLOB_RECURSE SOURCES DataStructures/* Serializer/*.cpp DataHandler/*.cpp
                          Worker/*.cpp RFmodem/RFmodem.h)

add_library(${PROJECT_NAME} ${SOURCES} ${SOURCES_RF} ${SOURCES_RF2} DataStructures/Avionics/StatusAV.cpp DataStructures/Avionics/StatusAV.h DataStructures/Avionics/StateValues.h DataStructures/GSE/GSEOrder.cpp DataStructures/GSE/GSEOrder.h DataStructures/GSE/GSEOrderValues.h DataStructures/GSE/GSESensors.cpp DataStructures/GSE/GSESensors.h)

target_include_directories(${PROJECT_NAME} PUBLIC DataStructures)
target_include_directories(${PROJECT_NAME} PUBLIC RFmodem)
target_include_directories(${PROJECT_NAME} PUBLIC RFmodem/lib/RadioHead)
target_include_directories(${PROJECT_NAME} PUBLIC Serializer)
target_include_directories(${PROJECT_NAME} PUBLIC DataHandler)
target_include_directories(${PROJECT_NAME} PUBLIC Worker)

target_include_directories(${PROJECT_NAME} PUBLIC ../RF-UI-Interface)
target_link_libraries(${PROJECT_NAME} RF-UI-Interface)

target_include_directories(${PROJECT_NAME} PUBLIC ../Logger)
target_link_libraries(${PROJECT_NAME} LogLib)

if (RUNNING_ON_RPI)
    target_link_libraries(${PROJECT_NAME} wiringPi) # control GPIO of RPi
    target_link_libraries(${PROJECT_NAME} crypt) # link crypt
endif (RUNNING_ON_RPI)


if (USE_GPS)
    target_link_libraries(${PROJECT_NAME} gps) # GPS
endif (USE_GPS)

if (USE_LORA)
    target_link_libraries(${PROJECT_NAME} RadioHead) # LoRa
endif (USE_LORA)

# Xbee serial
if (USE_XBEE)
    include_directories(RFmodem/lib/serial/include/)
    target_link_libraries(${PROJECT_NAME} serial)
endif (USE_XBEE)
