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
include CMakeFiles/Wave.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Wave.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Wave.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Wave.dir/flags.make

CMakeFiles/Wave.dir/wave.cpp.o: CMakeFiles/Wave.dir/flags.make
CMakeFiles/Wave.dir/wave.cpp.o: /home/oscar/Documents/Informatik/wave/wave.cpp
CMakeFiles/Wave.dir/wave.cpp.o: CMakeFiles/Wave.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/oscar/Documents/Informatik/wave/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Wave.dir/wave.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wave.dir/wave.cpp.o -MF CMakeFiles/Wave.dir/wave.cpp.o.d -o CMakeFiles/Wave.dir/wave.cpp.o -c /home/oscar/Documents/Informatik/wave/wave.cpp

CMakeFiles/Wave.dir/wave.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Wave.dir/wave.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oscar/Documents/Informatik/wave/wave.cpp > CMakeFiles/Wave.dir/wave.cpp.i

CMakeFiles/Wave.dir/wave.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Wave.dir/wave.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oscar/Documents/Informatik/wave/wave.cpp -o CMakeFiles/Wave.dir/wave.cpp.s

# Object files for target Wave
Wave_OBJECTS = \
"CMakeFiles/Wave.dir/wave.cpp.o"

# External object files for target Wave
Wave_EXTERNAL_OBJECTS =

Wave: CMakeFiles/Wave.dir/wave.cpp.o
Wave: CMakeFiles/Wave.dir/build.make
Wave: vcpkg_installed/x64-linux/debug/lib/libfmtd.a
Wave: /usr/lib/libOpenGL.so
Wave: /usr/lib/libEGL.so
Wave: graphics/libgraphics_manager.a
Wave: /usr/lib/libOpenGL.so
Wave: vcpkg_installed/x64-linux/debug/lib/libglfw3.a
Wave: /usr/lib/librt.a
Wave: /usr/lib/libm.so
Wave: /usr/lib/libX11.so
Wave: graphics/libtextRenderer.a
Wave: graphics/libresource_manager.a
Wave: graphics/libtexture.a
Wave: graphics/libshader.a
Wave: graphics/libstb_image.a
Wave: /usr/lib/libGLEW.so
Wave: vcpkg_installed/x64-linux/debug/lib/libfreetyped.a
Wave: vcpkg_installed/x64-linux/debug/lib/libbz2d.a
Wave: vcpkg_installed/x64-linux/debug/lib/libpng16d.a
Wave: vcpkg_installed/x64-linux/debug/lib/libz.a
Wave: vcpkg_installed/x64-linux/debug/lib/libbz2d.a
Wave: vcpkg_installed/x64-linux/debug/lib/libpng16d.a
Wave: vcpkg_installed/x64-linux/debug/lib/libz.a
Wave: vcpkg_installed/x64-linux/debug/lib/libbrotlidec.a
Wave: vcpkg_installed/x64-linux/debug/lib/libbrotlicommon.a
Wave: CMakeFiles/Wave.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/oscar/Documents/Informatik/wave/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Wave"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Wave.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Wave.dir/build: Wave
.PHONY : CMakeFiles/Wave.dir/build

CMakeFiles/Wave.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Wave.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Wave.dir/clean

CMakeFiles/Wave.dir/depend:
	cd /home/oscar/Documents/Informatik/wave/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oscar/Documents/Informatik/wave /home/oscar/Documents/Informatik/wave /home/oscar/Documents/Informatik/wave/build /home/oscar/Documents/Informatik/wave/build /home/oscar/Documents/Informatik/wave/build/CMakeFiles/Wave.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Wave.dir/depend

