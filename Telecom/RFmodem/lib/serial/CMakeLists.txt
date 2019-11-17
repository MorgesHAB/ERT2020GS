cmake_minimum_required(VERSION 3.7)
project(serial_cmake_lib LANGUAGES CXX)

configure_file(CMakeLists.txt.ddl ${CMAKE_BINARY_DIR}/serial-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/serial-download )
if(result)
    message(FATAL_ERROR "CMake download step for serial failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/serial-download )
if(result)
    message(FATAL_ERROR "CMake build step for serial failed: ${result}")
endif()

add_subdirectory(${CMAKE_BINARY_DIR}/serial-src
        ${CMAKE_BINARY_DIR}/serial-build)
