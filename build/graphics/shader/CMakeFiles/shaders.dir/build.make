# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/oscar/Documents/Informatik/wave

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oscar/Documents/Informatik/wave/build

# Include any dependencies generated for this target.
include graphics/shader/CMakeFiles/shaders.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include graphics/shader/CMakeFiles/shaders.dir/compiler_depend.make

# Include the progress variables for this target.
include graphics/shader/CMakeFiles/shaders.dir/progress.make

# Include the compile flags for this target's objects.
include graphics/shader/CMakeFiles/shaders.dir/flags.make

graphics/shader/CMakeFiles/shaders.dir/shaders.cpp.o: graphics/shader/CMakeFiles/shaders.dir/flags.make
graphics/shader/CMakeFiles/shaders.dir/shaders.cpp.o: /home/oscar/Documents/Informatik/wave/graphics/shader/shaders.cpp
graphics/shader/CMakeFiles/shaders.dir/shaders.cpp.o: graphics/shader/CMakeFiles/shaders.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/oscar/Documents/Informatik/wave/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object graphics/shader/CMakeFiles/shaders.dir/shaders.cpp.o"
	cd /home/oscar/Documents/Informatik/wave/build/graphics/shader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT graphics/shader/CMakeFiles/shaders.dir/shaders.cpp.o -MF CMakeFiles/shaders.dir/shaders.cpp.o.d -o CMakeFiles/shaders.dir/shaders.cpp.o -c /home/oscar/Documents/Informatik/wave/graphics/shader/shaders.cpp

graphics/shader/CMakeFiles/shaders.dir/shaders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/shaders.dir/shaders.cpp.i"
	cd /home/oscar/Documents/Informatik/wave/build/graphics/shader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oscar/Documents/Informatik/wave/graphics/shader/shaders.cpp > CMakeFiles/shaders.dir/shaders.cpp.i

graphics/shader/CMakeFiles/shaders.dir/shaders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/shaders.dir/shaders.cpp.s"
	cd /home/oscar/Documents/Informatik/wave/build/graphics/shader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oscar/Documents/Informatik/wave/graphics/shader/shaders.cpp -o CMakeFiles/shaders.dir/shaders.cpp.s

# Object files for target shaders
shaders_OBJECTS = \
"CMakeFiles/shaders.dir/shaders.cpp.o"

# External object files for target shaders
shaders_EXTERNAL_OBJECTS =

graphics/shader/libshaders.a: graphics/shader/CMakeFiles/shaders.dir/shaders.cpp.o
graphics/shader/libshaders.a: graphics/shader/CMakeFiles/shaders.dir/build.make
graphics/shader/libshaders.a: graphics/shader/CMakeFiles/shaders.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/oscar/Documents/Informatik/wave/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libshaders.a"
	cd /home/oscar/Documents/Informatik/wave/build/graphics/shader && $(CMAKE_COMMAND) -P CMakeFiles/shaders.dir/cmake_clean_target.cmake
	cd /home/oscar/Documents/Informatik/wave/build/graphics/shader && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shaders.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
graphics/shader/CMakeFiles/shaders.dir/build: graphics/shader/libshaders.a
.PHONY : graphics/shader/CMakeFiles/shaders.dir/build

graphics/shader/CMakeFiles/shaders.dir/clean:
	cd /home/oscar/Documents/Informatik/wave/build/graphics/shader && $(CMAKE_COMMAND) -P CMakeFiles/shaders.dir/cmake_clean.cmake
.PHONY : graphics/shader/CMakeFiles/shaders.dir/clean

graphics/shader/CMakeFiles/shaders.dir/depend:
	cd /home/oscar/Documents/Informatik/wave/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oscar/Documents/Informatik/wave /home/oscar/Documents/Informatik/wave/graphics/shader /home/oscar/Documents/Informatik/wave/build /home/oscar/Documents/Informatik/wave/build/graphics/shader /home/oscar/Documents/Informatik/wave/build/graphics/shader/CMakeFiles/shaders.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : graphics/shader/CMakeFiles/shaders.dir/depend
