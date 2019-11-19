cmake_minimum_required(VERSION 3.6.2)
project(Telecom)

if (USE_LORA)
    add_subdirectory(RFmodem/lib/RadioHead)
    file(GLOB SOURCES_RF RFmodem/LoRa.cpp)
endif (USE_LORA)
if (USE_XBEE)
    add_subdirectory(RFmodem/lib/serial)
    file(GLOB SOURCES_RF RFmodem/XBee.cpp)
endif (USE_XBEE)

file(GLOB SOURCES DataStructures/*.cpp Serializer/*.cpp DataHandler/*.cpp)

add_library(${PROJECT_NAME} ${SOURCES} ${SOURCES_RF})

target_include_directories(${PROJECT_NAME} PUBLIC DataStructures)
target_include_directories(${PROJECT_NAME} PUBLIC RFmodem)
target_include_directories(${PROJECT_NAME} PUBLIC RFmodem/lib/RadioHead)
target_include_directories(${PROJECT_NAME} PUBLIC Serializer)
target_include_directories(${PROJECT_NAME} PUBLIC DataHandler)

target_link_libraries(${PROJECT_NAME} gps) # GPS

if (USE_LORA)
target_link_libraries(${PROJECT_NAME} RadioHead) # LoRa
endif (USE_LORA)

# Xbee serial
if (USE_XBEE)
    include_directories(${CMAKE_BINARY_DIR}/serial-src/include/)
    target_link_libraries(${PROJECT_NAME} serial)
endif (USE_XBEE)


