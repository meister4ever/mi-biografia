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
include src/CMakeFiles/Bloque.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Bloque.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Bloque.dir/flags.make

src/CMakeFiles/Bloque.dir/bloque.cpp.o: src/CMakeFiles/Bloque.dir/flags.make
src/CMakeFiles/Bloque.dir/bloque.cpp.o: ../src/bloque.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/Bloque.dir/bloque.cpp.o"
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Bloque.dir/bloque.cpp.o -c /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/src/bloque.cpp

src/CMakeFiles/Bloque.dir/bloque.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bloque.dir/bloque.cpp.i"
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/src/bloque.cpp > CMakeFiles/Bloque.dir/bloque.cpp.i

src/CMakeFiles/Bloque.dir/bloque.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bloque.dir/bloque.cpp.s"
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/src/bloque.cpp -o CMakeFiles/Bloque.dir/bloque.cpp.s

src/CMakeFiles/Bloque.dir/bloque.cpp.o.requires:
.PHONY : src/CMakeFiles/Bloque.dir/bloque.cpp.o.requires

src/CMakeFiles/Bloque.dir/bloque.cpp.o.provides: src/CMakeFiles/Bloque.dir/bloque.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/Bloque.dir/build.make src/CMakeFiles/Bloque.dir/bloque.cpp.o.provides.build
.PHONY : src/CMakeFiles/Bloque.dir/bloque.cpp.o.provides

src/CMakeFiles/Bloque.dir/bloque.cpp.o.provides.build: src/CMakeFiles/Bloque.dir/bloque.cpp.o

# Object files for target Bloque
Bloque_OBJECTS = \
"CMakeFiles/Bloque.dir/bloque.cpp.o"

# External object files for target Bloque
Bloque_EXTERNAL_OBJECTS =

src/libBloque.a: src/CMakeFiles/Bloque.dir/bloque.cpp.o
src/libBloque.a: src/CMakeFiles/Bloque.dir/build.make
src/libBloque.a: src/CMakeFiles/Bloque.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libBloque.a"
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Bloque.dir/cmake_clean_target.cmake
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bloque.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Bloque.dir/build: src/libBloque.a
.PHONY : src/CMakeFiles/Bloque.dir/build

src/CMakeFiles/Bloque.dir/requires: src/CMakeFiles/Bloque.dir/bloque.cpp.o.requires
.PHONY : src/CMakeFiles/Bloque.dir/requires

src/CMakeFiles/Bloque.dir/clean:
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Bloque.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Bloque.dir/clean

src/CMakeFiles/Bloque.dir/depend:
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/src /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src/CMakeFiles/Bloque.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Bloque.dir/depend

