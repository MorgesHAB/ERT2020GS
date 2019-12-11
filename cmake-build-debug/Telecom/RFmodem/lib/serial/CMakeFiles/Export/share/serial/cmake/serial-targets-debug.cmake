#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "serial" for configuration "Debug"
set_property(TARGET serial APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(serial PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "rt;pthread"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libserial.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS serial )
list(APPEND _IMPORT_CHECK_FILES_FOR_serial "${_IMPORT_PREFIX}/lib/libserial.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
