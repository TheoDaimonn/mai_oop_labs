# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /workspaces/mai_oop_labs/lr1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/mai_oop_labs/lr1/build

# Include any dependencies generated for this target.
include CMakeFiles/lr1_exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lr1_exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lr1_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lr1_exe.dir/flags.make

CMakeFiles/lr1_exe.dir/main.cpp.o: CMakeFiles/lr1_exe.dir/flags.make
CMakeFiles/lr1_exe.dir/main.cpp.o: /workspaces/mai_oop_labs/lr1/main.cpp
CMakeFiles/lr1_exe.dir/main.cpp.o: CMakeFiles/lr1_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/mai_oop_labs/lr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lr1_exe.dir/main.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lr1_exe.dir/main.cpp.o -MF CMakeFiles/lr1_exe.dir/main.cpp.o.d -o CMakeFiles/lr1_exe.dir/main.cpp.o -c /workspaces/mai_oop_labs/lr1/main.cpp

CMakeFiles/lr1_exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lr1_exe.dir/main.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/mai_oop_labs/lr1/main.cpp > CMakeFiles/lr1_exe.dir/main.cpp.i

CMakeFiles/lr1_exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lr1_exe.dir/main.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/mai_oop_labs/lr1/main.cpp -o CMakeFiles/lr1_exe.dir/main.cpp.s

# Object files for target lr1_exe
lr1_exe_OBJECTS = \
"CMakeFiles/lr1_exe.dir/main.cpp.o"

# External object files for target lr1_exe
lr1_exe_EXTERNAL_OBJECTS =

lr1_exe: CMakeFiles/lr1_exe.dir/main.cpp.o
lr1_exe: CMakeFiles/lr1_exe.dir/build.make
lr1_exe: liblr1_lib.a
lr1_exe: CMakeFiles/lr1_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/mai_oop_labs/lr1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lr1_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lr1_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lr1_exe.dir/build: lr1_exe
.PHONY : CMakeFiles/lr1_exe.dir/build

CMakeFiles/lr1_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lr1_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lr1_exe.dir/clean

CMakeFiles/lr1_exe.dir/depend:
	cd /workspaces/mai_oop_labs/lr1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/mai_oop_labs/lr1 /workspaces/mai_oop_labs/lr1 /workspaces/mai_oop_labs/lr1/build /workspaces/mai_oop_labs/lr1/build /workspaces/mai_oop_labs/lr1/build/CMakeFiles/lr1_exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lr1_exe.dir/depend

