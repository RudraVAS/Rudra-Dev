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
CMAKE_COMMAND = /snap/cmake/599/bin/cmake

# The command to remove a file.
RM = /snap/cmake/599/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tronifier/Rudra-Dev/modules/dp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tronifier/Rudra-Dev/modules/dp/bin

# Include any dependencies generated for this target.
include CMakeFiles/rudra.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rudra.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rudra.dir/flags.make

CMakeFiles/rudra.dir/src/csv.o: CMakeFiles/rudra.dir/flags.make
CMakeFiles/rudra.dir/src/csv.o: ../src/csv.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tronifier/Rudra-Dev/modules/dp/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rudra.dir/src/csv.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rudra.dir/src/csv.o -c /home/tronifier/Rudra-Dev/modules/dp/src/csv.c

CMakeFiles/rudra.dir/src/csv.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rudra.dir/src/csv.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tronifier/Rudra-Dev/modules/dp/src/csv.c > CMakeFiles/rudra.dir/src/csv.i

CMakeFiles/rudra.dir/src/csv.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rudra.dir/src/csv.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tronifier/Rudra-Dev/modules/dp/src/csv.c -o CMakeFiles/rudra.dir/src/csv.s

CMakeFiles/rudra.dir/src/normalization.o: CMakeFiles/rudra.dir/flags.make
CMakeFiles/rudra.dir/src/normalization.o: ../src/normalization.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tronifier/Rudra-Dev/modules/dp/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/rudra.dir/src/normalization.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rudra.dir/src/normalization.o -c /home/tronifier/Rudra-Dev/modules/dp/src/normalization.c

CMakeFiles/rudra.dir/src/normalization.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rudra.dir/src/normalization.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tronifier/Rudra-Dev/modules/dp/src/normalization.c > CMakeFiles/rudra.dir/src/normalization.i

CMakeFiles/rudra.dir/src/normalization.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rudra.dir/src/normalization.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tronifier/Rudra-Dev/modules/dp/src/normalization.c -o CMakeFiles/rudra.dir/src/normalization.s

CMakeFiles/rudra.dir/src/vector.o: CMakeFiles/rudra.dir/flags.make
CMakeFiles/rudra.dir/src/vector.o: ../src/vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tronifier/Rudra-Dev/modules/dp/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/rudra.dir/src/vector.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rudra.dir/src/vector.o -c /home/tronifier/Rudra-Dev/modules/dp/src/vector.c

CMakeFiles/rudra.dir/src/vector.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rudra.dir/src/vector.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tronifier/Rudra-Dev/modules/dp/src/vector.c > CMakeFiles/rudra.dir/src/vector.i

CMakeFiles/rudra.dir/src/vector.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rudra.dir/src/vector.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tronifier/Rudra-Dev/modules/dp/src/vector.c -o CMakeFiles/rudra.dir/src/vector.s

CMakeFiles/rudra.dir/src/xalloc.o: CMakeFiles/rudra.dir/flags.make
CMakeFiles/rudra.dir/src/xalloc.o: ../src/xalloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tronifier/Rudra-Dev/modules/dp/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/rudra.dir/src/xalloc.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rudra.dir/src/xalloc.o -c /home/tronifier/Rudra-Dev/modules/dp/src/xalloc.c

CMakeFiles/rudra.dir/src/xalloc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rudra.dir/src/xalloc.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tronifier/Rudra-Dev/modules/dp/src/xalloc.c > CMakeFiles/rudra.dir/src/xalloc.i

CMakeFiles/rudra.dir/src/xalloc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rudra.dir/src/xalloc.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tronifier/Rudra-Dev/modules/dp/src/xalloc.c -o CMakeFiles/rudra.dir/src/xalloc.s

CMakeFiles/rudra.dir/test/main.o: CMakeFiles/rudra.dir/flags.make
CMakeFiles/rudra.dir/test/main.o: ../test/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tronifier/Rudra-Dev/modules/dp/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/rudra.dir/test/main.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rudra.dir/test/main.o -c /home/tronifier/Rudra-Dev/modules/dp/test/main.c

CMakeFiles/rudra.dir/test/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rudra.dir/test/main.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tronifier/Rudra-Dev/modules/dp/test/main.c > CMakeFiles/rudra.dir/test/main.i

CMakeFiles/rudra.dir/test/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rudra.dir/test/main.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tronifier/Rudra-Dev/modules/dp/test/main.c -o CMakeFiles/rudra.dir/test/main.s

# Object files for target rudra
rudra_OBJECTS = \
"CMakeFiles/rudra.dir/src/csv.o" \
"CMakeFiles/rudra.dir/src/normalization.o" \
"CMakeFiles/rudra.dir/src/vector.o" \
"CMakeFiles/rudra.dir/src/xalloc.o" \
"CMakeFiles/rudra.dir/test/main.o"

# External object files for target rudra
rudra_EXTERNAL_OBJECTS =

rudra: CMakeFiles/rudra.dir/src/csv.o
rudra: CMakeFiles/rudra.dir/src/normalization.o
rudra: CMakeFiles/rudra.dir/src/vector.o
rudra: CMakeFiles/rudra.dir/src/xalloc.o
rudra: CMakeFiles/rudra.dir/test/main.o
rudra: CMakeFiles/rudra.dir/build.make
rudra: CMakeFiles/rudra.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tronifier/Rudra-Dev/modules/dp/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable rudra"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rudra.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rudra.dir/build: rudra

.PHONY : CMakeFiles/rudra.dir/build

CMakeFiles/rudra.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rudra.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rudra.dir/clean

CMakeFiles/rudra.dir/depend:
	cd /home/tronifier/Rudra-Dev/modules/dp/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tronifier/Rudra-Dev/modules/dp /home/tronifier/Rudra-Dev/modules/dp /home/tronifier/Rudra-Dev/modules/dp/bin /home/tronifier/Rudra-Dev/modules/dp/bin /home/tronifier/Rudra-Dev/modules/dp/bin/CMakeFiles/rudra.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rudra.dir/depend

