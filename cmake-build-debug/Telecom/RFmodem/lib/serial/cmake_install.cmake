# Install script for directory: /home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/Telecom/RFmodem/lib/serial

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug/Telecom/RFmodem/lib/serial/libserial.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/serial" TYPE FILE FILES
    "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/Telecom/RFmodem/lib/serial/include/serial/serial.h"
    "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/Telecom/RFmodem/lib/serial/include/serial/v8stdint.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/serial/cmake/serial-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/serial/cmake/serial-targets.cmake"
         "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug/Telecom/RFmodem/lib/serial/CMakeFiles/Export/share/serial/cmake/serial-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/serial/cmake/serial-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/serial/cmake/serial-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial/cmake" TYPE FILE FILES "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug/Telecom/RFmodem/lib/serial/CMakeFiles/Export/share/serial/cmake/serial-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial/cmake" TYPE FILE FILES "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug/Telecom/RFmodem/lib/serial/CMakeFiles/Export/share/serial/cmake/serial-targets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial/cmake" TYPE FILE FILES
    "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake/serialConfig.cmake"
    "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake/serialConfigVersion.cmake"
    )
endif()

