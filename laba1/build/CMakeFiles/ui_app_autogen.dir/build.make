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

# Utility rule file for ui_app_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/ui_app_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ui_app_autogen.dir/progress.make

CMakeFiles/ui_app_autogen: ui_app_autogen/timestamp

ui_app_autogen/timestamp: /usr/bin/moc
ui_app_autogen/timestamp: CMakeFiles/ui_app_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/petr/Documents/labs3sem/laba1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target ui_app"
	/usr/bin/cmake -E cmake_autogen /home/petr/Documents/labs3sem/laba1/build/CMakeFiles/ui_app_autogen.dir/AutogenInfo.json ""
	/usr/bin/cmake -E touch /home/petr/Documents/labs3sem/laba1/build/ui_app_autogen/timestamp

CMakeFiles/ui_app_autogen.dir/codegen:
.PHONY : CMakeFiles/ui_app_autogen.dir/codegen

ui_app_autogen: CMakeFiles/ui_app_autogen
ui_app_autogen: ui_app_autogen/timestamp
ui_app_autogen: CMakeFiles/ui_app_autogen.dir/build.make
.PHONY : ui_app_autogen

# Rule to build all files generated by this target.
CMakeFiles/ui_app_autogen.dir/build: ui_app_autogen
.PHONY : CMakeFiles/ui_app_autogen.dir/build

CMakeFiles/ui_app_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ui_app_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ui_app_autogen.dir/clean

CMakeFiles/ui_app_autogen.dir/depend:
	cd /home/petr/Documents/labs3sem/laba1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/petr/Documents/labs3sem/laba1 /home/petr/Documents/labs3sem/laba1 /home/petr/Documents/labs3sem/laba1/build /home/petr/Documents/labs3sem/laba1/build /home/petr/Documents/labs3sem/laba1/build/CMakeFiles/ui_app_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ui_app_autogen.dir/depend

