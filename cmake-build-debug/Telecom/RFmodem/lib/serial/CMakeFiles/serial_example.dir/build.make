# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/stephanie/Bureau/clion-2019.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/stephanie/Bureau/clion-2019.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug"

# Include any dependencies generated for this target.
include Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/depend.make

# Include the progress variables for this target.
include Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/progress.make

# Include the compile flags for this target's objects.
include Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/flags.make

Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o: Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/flags.make
Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o: ../Telecom/RFmodem/lib/serial/examples/serial_example.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o"
	cd "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug/Telecom/RFmodem/lib/serial" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serial_example.dir/examples/serial_example.cc.o -c "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/Telecom/RFmodem/lib/serial/examples/serial_example.cc"

Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial_example.dir/examples/serial_example.cc.i"
	cd "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug/Telecom/RFmodem/lib/serial" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/Telecom/RFmodem/lib/serial/examples/serial_example.cc" > CMakeFiles/serial_example.dir/examples/serial_example.cc.i

Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial_example.dir/examples/serial_example.cc.s"
	cd "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug/Telecom/RFmodem/lib/serial" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/Telecom/RFmodem/lib/serial/examples/serial_example.cc" -o CMakeFiles/serial_example.dir/examples/serial_example.cc.s

# Object files for target serial_example
serial_example_OBJECTS = \
"CMakeFiles/serial_example.dir/examples/serial_example.cc.o"

# External object files for target serial_example
serial_example_EXTERNAL_OBJECTS =

Telecom/RFmodem/lib/serial/serial_example: Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o
Telecom/RFmodem/lib/serial/serial_example: Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/build.make
Telecom/RFmodem/lib/serial/serial_example: Telecom/RFmodem/lib/serial/libserial.a
Telecom/RFmodem/lib/serial/serial_example: Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable serial_example"
	cd "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug/Telecom/RFmodem/lib/serial" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/build: Telecom/RFmodem/lib/serial/serial_example

.PHONY : Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/build

Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/clean:
	cd "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug/Telecom/RFmodem/lib/serial" && $(CMAKE_COMMAND) -P CMakeFiles/serial_example.dir/cmake_clean.cmake
.PHONY : Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/clean

Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/depend:
	cd "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS" "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/Telecom/RFmodem/lib/serial" "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug" "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug/Telecom/RFmodem/lib/serial" "/home/stephanie/Documents/ERT/Code Lionel/ERT2020GS/cmake-build-debug/Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : Telecom/RFmodem/lib/serial/CMakeFiles/serial_example.dir/depend

