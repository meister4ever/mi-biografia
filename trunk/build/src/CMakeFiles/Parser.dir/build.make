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
include src/CMakeFiles/Parser.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Parser.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Parser.dir/flags.make

src/CMakeFiles/Parser.dir/parser.cpp.o: src/CMakeFiles/Parser.dir/flags.make
src/CMakeFiles/Parser.dir/parser.cpp.o: ../src/parser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/Parser.dir/parser.cpp.o"
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Parser.dir/parser.cpp.o -c /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/src/parser.cpp

src/CMakeFiles/Parser.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Parser.dir/parser.cpp.i"
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/src/parser.cpp > CMakeFiles/Parser.dir/parser.cpp.i

src/CMakeFiles/Parser.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Parser.dir/parser.cpp.s"
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/src/parser.cpp -o CMakeFiles/Parser.dir/parser.cpp.s

src/CMakeFiles/Parser.dir/parser.cpp.o.requires:
.PHONY : src/CMakeFiles/Parser.dir/parser.cpp.o.requires

src/CMakeFiles/Parser.dir/parser.cpp.o.provides: src/CMakeFiles/Parser.dir/parser.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/Parser.dir/build.make src/CMakeFiles/Parser.dir/parser.cpp.o.provides.build
.PHONY : src/CMakeFiles/Parser.dir/parser.cpp.o.provides

src/CMakeFiles/Parser.dir/parser.cpp.o.provides.build: src/CMakeFiles/Parser.dir/parser.cpp.o

# Object files for target Parser
Parser_OBJECTS = \
"CMakeFiles/Parser.dir/parser.cpp.o"

# External object files for target Parser
Parser_EXTERNAL_OBJECTS =

src/libParser.a: src/CMakeFiles/Parser.dir/parser.cpp.o
src/libParser.a: src/CMakeFiles/Parser.dir/build.make
src/libParser.a: src/CMakeFiles/Parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libParser.a"
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Parser.dir/cmake_clean_target.cmake
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Parser.dir/build: src/libParser.a
.PHONY : src/CMakeFiles/Parser.dir/build

src/CMakeFiles/Parser.dir/requires: src/CMakeFiles/Parser.dir/parser.cpp.o.requires
.PHONY : src/CMakeFiles/Parser.dir/requires

src/CMakeFiles/Parser.dir/clean:
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Parser.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Parser.dir/clean

src/CMakeFiles/Parser.dir/depend:
	cd /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/src /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src /home/nacho/Documentos/Desarrollo/TP1/TP1temp/mi-biografia/build/src/CMakeFiles/Parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Parser.dir/depend

