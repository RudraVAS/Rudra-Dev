# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /snap/cmake/549/bin/cmake

# The command to remove a file.
RM = /snap/cmake/549/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tronifier/Rudra-Dev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tronifier/Rudra-Dev/build

# Include any dependencies generated for this target.
include CMakeFiles/rudra.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rudra.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rudra.dir/flags.make

CMakeFiles/rudra.dir/rudra_core.c.o: CMakeFiles/rudra.dir/flags.make
CMakeFiles/rudra.dir/rudra_core.c.o: ../rudra_core.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tronifier/Rudra-Dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rudra.dir/rudra_core.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rudra.dir/rudra_core.c.o -c /home/tronifier/Rudra-Dev/rudra_core.c

CMakeFiles/rudra.dir/rudra_core.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rudra.dir/rudra_core.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tronifier/Rudra-Dev/rudra_core.c > CMakeFiles/rudra.dir/rudra_core.c.i

CMakeFiles/rudra.dir/rudra_core.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rudra.dir/rudra_core.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tronifier/Rudra-Dev/rudra_core.c -o CMakeFiles/rudra.dir/rudra_core.c.s

# Object files for target rudra
rudra_OBJECTS = \
"CMakeFiles/rudra.dir/rudra_core.c.o"

# External object files for target rudra
rudra_EXTERNAL_OBJECTS =

rudra: CMakeFiles/rudra.dir/rudra_core.c.o
rudra: CMakeFiles/rudra.dir/build.make
rudra: CMakeFiles/rudra.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tronifier/Rudra-Dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable rudra"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rudra.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rudra.dir/build: rudra

.PHONY : CMakeFiles/rudra.dir/build

CMakeFiles/rudra.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rudra.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rudra.dir/clean

CMakeFiles/rudra.dir/depend:
	cd /home/tronifier/Rudra-Dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tronifier/Rudra-Dev /home/tronifier/Rudra-Dev /home/tronifier/Rudra-Dev/build /home/tronifier/Rudra-Dev/build /home/tronifier/Rudra-Dev/build/CMakeFiles/rudra.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rudra.dir/depend
