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
CMAKE_SOURCE_DIR = /home/petr/Documents/labs3sem/laba1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/petr/Documents/labs3sem/laba1/build

# Utility rule file for SmartListSequenceTests_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/SmartListSequenceTests_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SmartListSequenceTests_autogen.dir/progress.make

CMakeFiles/SmartListSequenceTests_autogen: SmartListSequenceTests_autogen/timestamp

SmartListSequenceTests_autogen/timestamp: /usr/bin/moc
SmartListSequenceTests_autogen/timestamp: CMakeFiles/SmartListSequenceTests_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/petr/Documents/labs3sem/laba1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target SmartListSequenceTests"
	/usr/bin/cmake -E cmake_autogen /home/petr/Documents/labs3sem/laba1/build/CMakeFiles/SmartListSequenceTests_autogen.dir/AutogenInfo.json ""
	/usr/bin/cmake -E touch /home/petr/Documents/labs3sem/laba1/build/SmartListSequenceTests_autogen/timestamp

CMakeFiles/SmartListSequenceTests_autogen.dir/codegen:
.PHONY : CMakeFiles/SmartListSequenceTests_autogen.dir/codegen

SmartListSequenceTests_autogen: CMakeFiles/SmartListSequenceTests_autogen
SmartListSequenceTests_autogen: SmartListSequenceTests_autogen/timestamp
SmartListSequenceTests_autogen: CMakeFiles/SmartListSequenceTests_autogen.dir/build.make
.PHONY : SmartListSequenceTests_autogen

# Rule to build all files generated by this target.
CMakeFiles/SmartListSequenceTests_autogen.dir/build: SmartListSequenceTests_autogen
.PHONY : CMakeFiles/SmartListSequenceTests_autogen.dir/build

CMakeFiles/SmartListSequenceTests_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SmartListSequenceTests_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SmartListSequenceTests_autogen.dir/clean

CMakeFiles/SmartListSequenceTests_autogen.dir/depend:
	cd /home/petr/Documents/labs3sem/laba1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/petr/Documents/labs3sem/laba1 /home/petr/Documents/labs3sem/laba1 /home/petr/Documents/labs3sem/laba1/build /home/petr/Documents/labs3sem/laba1/build /home/petr/Documents/labs3sem/laba1/build/CMakeFiles/SmartListSequenceTests_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SmartListSequenceTests_autogen.dir/depend

