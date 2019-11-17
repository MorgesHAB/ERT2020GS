cmake_minimum_required(VERSION 3.7)

project(serial-download NONE)

include(ExternalProject)
ExternalProject_Add(
  serial
  GIT_REPOSITORY    https://github.com/clementnuss/serial.git
  GIT_TAG           master
  SOURCE_DIR        "${CMAKE_BINARY_DIR}/serial-src"
  BINARY_DIR        "${CMAKE_BINARY_DIR}/serial-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)


