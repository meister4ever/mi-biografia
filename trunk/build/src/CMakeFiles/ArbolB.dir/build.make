# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build

# Include any dependencies generated for this target.
include src/CMakeFiles/ArbolB.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ArbolB.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ArbolB.dir/flags.make

src/CMakeFiles/ArbolB.dir/arbolB.cpp.o: src/CMakeFiles/ArbolB.dir/flags.make
src/CMakeFiles/ArbolB.dir/arbolB.cpp.o: ../src/arbolB.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/ArbolB.dir/arbolB.cpp.o"
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ArbolB.dir/arbolB.cpp.o -c /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/src/arbolB.cpp

src/CMakeFiles/ArbolB.dir/arbolB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ArbolB.dir/arbolB.cpp.i"
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/src/arbolB.cpp > CMakeFiles/ArbolB.dir/arbolB.cpp.i

src/CMakeFiles/ArbolB.dir/arbolB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ArbolB.dir/arbolB.cpp.s"
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/src/arbolB.cpp -o CMakeFiles/ArbolB.dir/arbolB.cpp.s

src/CMakeFiles/ArbolB.dir/arbolB.cpp.o.requires:
.PHONY : src/CMakeFiles/ArbolB.dir/arbolB.cpp.o.requires

src/CMakeFiles/ArbolB.dir/arbolB.cpp.o.provides: src/CMakeFiles/ArbolB.dir/arbolB.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ArbolB.dir/build.make src/CMakeFiles/ArbolB.dir/arbolB.cpp.o.provides.build
.PHONY : src/CMakeFiles/ArbolB.dir/arbolB.cpp.o.provides

src/CMakeFiles/ArbolB.dir/arbolB.cpp.o.provides.build: src/CMakeFiles/ArbolB.dir/arbolB.cpp.o

# Object files for target ArbolB
ArbolB_OBJECTS = \
"CMakeFiles/ArbolB.dir/arbolB.cpp.o"

# External object files for target ArbolB
ArbolB_EXTERNAL_OBJECTS =

src/libArbolB.a: src/CMakeFiles/ArbolB.dir/arbolB.cpp.o
src/libArbolB.a: src/CMakeFiles/ArbolB.dir/build.make
src/libArbolB.a: src/CMakeFiles/ArbolB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libArbolB.a"
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ArbolB.dir/cmake_clean_target.cmake
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ArbolB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ArbolB.dir/build: src/libArbolB.a
.PHONY : src/CMakeFiles/ArbolB.dir/build

src/CMakeFiles/ArbolB.dir/requires: src/CMakeFiles/ArbolB.dir/arbolB.cpp.o.requires
.PHONY : src/CMakeFiles/ArbolB.dir/requires

src/CMakeFiles/ArbolB.dir/clean:
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ArbolB.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ArbolB.dir/clean

src/CMakeFiles/ArbolB.dir/depend:
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/src /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src/CMakeFiles/ArbolB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ArbolB.dir/depend

