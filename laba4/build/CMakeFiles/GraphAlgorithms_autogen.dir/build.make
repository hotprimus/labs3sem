# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/petr/Documents/labs3sem/laba4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/petr/Documents/labs3sem/laba4/build

# Utility rule file for GraphAlgorithms_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/GraphAlgorithms_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GraphAlgorithms_autogen.dir/progress.make

CMakeFiles/GraphAlgorithms_autogen: GraphAlgorithms_autogen/timestamp

GraphAlgorithms_autogen/timestamp: /usr/bin/moc
GraphAlgorithms_autogen/timestamp: /usr/bin/uic
GraphAlgorithms_autogen/timestamp: CMakeFiles/GraphAlgorithms_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/petr/Documents/labs3sem/laba4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target GraphAlgorithms"
	/usr/bin/cmake -E cmake_autogen /home/petr/Documents/labs3sem/laba4/build/CMakeFiles/GraphAlgorithms_autogen.dir/AutogenInfo.json ""
	/usr/bin/cmake -E touch /home/petr/Documents/labs3sem/laba4/build/GraphAlgorithms_autogen/timestamp

CMakeFiles/GraphAlgorithms_autogen.dir/codegen:
.PHONY : CMakeFiles/GraphAlgorithms_autogen.dir/codegen

GraphAlgorithms_autogen: CMakeFiles/GraphAlgorithms_autogen
GraphAlgorithms_autogen: GraphAlgorithms_autogen/timestamp
GraphAlgorithms_autogen: CMakeFiles/GraphAlgorithms_autogen.dir/build.make
.PHONY : GraphAlgorithms_autogen

# Rule to build all files generated by this target.
CMakeFiles/GraphAlgorithms_autogen.dir/build: GraphAlgorithms_autogen
.PHONY : CMakeFiles/GraphAlgorithms_autogen.dir/build

CMakeFiles/GraphAlgorithms_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GraphAlgorithms_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GraphAlgorithms_autogen.dir/clean

CMakeFiles/GraphAlgorithms_autogen.dir/depend:
	cd /home/petr/Documents/labs3sem/laba4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/petr/Documents/labs3sem/laba4 /home/petr/Documents/labs3sem/laba4 /home/petr/Documents/labs3sem/laba4/build /home/petr/Documents/labs3sem/laba4/build /home/petr/Documents/labs3sem/laba4/build/CMakeFiles/GraphAlgorithms_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/GraphAlgorithms_autogen.dir/depend

