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
CMAKE_SOURCE_DIR = /home/petr/Documents/labs3sem/laba2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/petr/Documents/labs3sem/laba2/build

# Include any dependencies generated for this target.
include CMakeFiles/SortingTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SortingTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SortingTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SortingTests.dir/flags.make

SortingTests_autogen/timestamp: /usr/lib/qt6/moc
SortingTests_autogen/timestamp: /usr/lib/qt6/uic
SortingTests_autogen/timestamp: CMakeFiles/SortingTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/petr/Documents/labs3sem/laba2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target SortingTests"
	/usr/bin/cmake -E cmake_autogen /home/petr/Documents/labs3sem/laba2/build/CMakeFiles/SortingTests_autogen.dir/AutogenInfo.json ""
	/usr/bin/cmake -E touch /home/petr/Documents/labs3sem/laba2/build/SortingTests_autogen/timestamp

CMakeFiles/SortingTests.dir/codegen:
.PHONY : CMakeFiles/SortingTests.dir/codegen

CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.o: CMakeFiles/SortingTests.dir/flags.make
CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.o: SortingTests_autogen/mocs_compilation.cpp
CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.o: CMakeFiles/SortingTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/petr/Documents/labs3sem/laba2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.o -MF CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.o -c /home/petr/Documents/labs3sem/laba2/build/SortingTests_autogen/mocs_compilation.cpp

CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petr/Documents/labs3sem/laba2/build/SortingTests_autogen/mocs_compilation.cpp > CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.i

CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petr/Documents/labs3sem/laba2/build/SortingTests_autogen/mocs_compilation.cpp -o CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.s

CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.o: CMakeFiles/SortingTests.dir/flags.make
CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.o: /home/petr/Documents/labs3sem/laba2/tests/SortingTests.cpp
CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.o: CMakeFiles/SortingTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/petr/Documents/labs3sem/laba2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.o -MF CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.o.d -o CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.o -c /home/petr/Documents/labs3sem/laba2/tests/SortingTests.cpp

CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petr/Documents/labs3sem/laba2/tests/SortingTests.cpp > CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.i

CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petr/Documents/labs3sem/laba2/tests/SortingTests.cpp -o CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.s

# Object files for target SortingTests
SortingTests_OBJECTS = \
"CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.o"

# External object files for target SortingTests
SortingTests_EXTERNAL_OBJECTS =

SortingTests: CMakeFiles/SortingTests.dir/SortingTests_autogen/mocs_compilation.cpp.o
SortingTests: CMakeFiles/SortingTests.dir/tests/SortingTests.cpp.o
SortingTests: CMakeFiles/SortingTests.dir/build.make
SortingTests: CMakeFiles/SortingTests.dir/compiler_depend.ts
SortingTests: /usr/lib/libQt6Test.so.6.8.0
SortingTests: /usr/lib/libQt6Core.so.6.8.0
SortingTests: CMakeFiles/SortingTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/petr/Documents/labs3sem/laba2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable SortingTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SortingTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SortingTests.dir/build: SortingTests
.PHONY : CMakeFiles/SortingTests.dir/build

CMakeFiles/SortingTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SortingTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SortingTests.dir/clean

CMakeFiles/SortingTests.dir/depend: SortingTests_autogen/timestamp
	cd /home/petr/Documents/labs3sem/laba2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/petr/Documents/labs3sem/laba2 /home/petr/Documents/labs3sem/laba2 /home/petr/Documents/labs3sem/laba2/build /home/petr/Documents/labs3sem/laba2/build /home/petr/Documents/labs3sem/laba2/build/CMakeFiles/SortingTests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SortingTests.dir/depend
