# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/felixchen/CLionProjects/kr-exercises

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/felixchen/CLionProjects/kr-exercises/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CPorgramming.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPorgramming.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPorgramming.dir/flags.make

CMakeFiles/CPorgramming.dir/main.c.o: CMakeFiles/CPorgramming.dir/flags.make
CMakeFiles/CPorgramming.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/felixchen/CLionProjects/kr-exercises/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CPorgramming.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CPorgramming.dir/main.c.o -c /Users/felixchen/CLionProjects/kr-exercises/main.c

CMakeFiles/CPorgramming.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CPorgramming.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/felixchen/CLionProjects/kr-exercises/main.c > CMakeFiles/CPorgramming.dir/main.c.i

CMakeFiles/CPorgramming.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CPorgramming.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/felixchen/CLionProjects/kr-exercises/main.c -o CMakeFiles/CPorgramming.dir/main.c.s

# Object files for target CPorgramming
CPorgramming_OBJECTS = \
"CMakeFiles/CPorgramming.dir/main.c.o"

# External object files for target CPorgramming
CPorgramming_EXTERNAL_OBJECTS =

CPorgramming: CMakeFiles/CPorgramming.dir/main.c.o
CPorgramming: CMakeFiles/CPorgramming.dir/build.make
CPorgramming: CMakeFiles/CPorgramming.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/felixchen/CLionProjects/kr-exercises/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable CPorgramming"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPorgramming.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPorgramming.dir/build: CPorgramming

.PHONY : CMakeFiles/CPorgramming.dir/build

CMakeFiles/CPorgramming.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPorgramming.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPorgramming.dir/clean

CMakeFiles/CPorgramming.dir/depend:
	cd /Users/felixchen/CLionProjects/kr-exercises/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/felixchen/CLionProjects/kr-exercises /Users/felixchen/CLionProjects/kr-exercises /Users/felixchen/CLionProjects/kr-exercises/cmake-build-debug /Users/felixchen/CLionProjects/kr-exercises/cmake-build-debug /Users/felixchen/CLionProjects/kr-exercises/cmake-build-debug/CMakeFiles/CPorgramming.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPorgramming.dir/depend

