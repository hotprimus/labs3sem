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
include CMakeFiles/SortingApp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SortingApp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SortingApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SortingApp.dir/flags.make

SortingApp_autogen/timestamp: /usr/lib/qt6/moc
SortingApp_autogen/timestamp: /usr/lib/qt6/uic
SortingApp_autogen/timestamp: CMakeFiles/SortingApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/petr/Documents/labs3sem/laba2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target SortingApp"
	/usr/bin/cmake -E cmake_autogen /home/petr/Documents/labs3sem/laba2/build/CMakeFiles/SortingApp_autogen.dir/AutogenInfo.json ""
	/usr/bin/cmake -E touch /home/petr/Documents/labs3sem/laba2/build/SortingApp_autogen/timestamp

CMakeFiles/SortingApp.dir/codegen:
.PHONY : CMakeFiles/SortingApp.dir/codegen

CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.o: CMakeFiles/SortingApp.dir/flags.make
CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.o: SortingApp_autogen/mocs_compilation.cpp
CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.o: CMakeFiles/SortingApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/petr/Documents/labs3sem/laba2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.o -MF CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.o -c /home/petr/Documents/labs3sem/laba2/build/SortingApp_autogen/mocs_compilation.cpp

CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petr/Documents/labs3sem/laba2/build/SortingApp_autogen/mocs_compilation.cpp > CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.i

CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petr/Documents/labs3sem/laba2/build/SortingApp_autogen/mocs_compilation.cpp -o CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.s

CMakeFiles/SortingApp.dir/main.cpp.o: CMakeFiles/SortingApp.dir/flags.make
CMakeFiles/SortingApp.dir/main.cpp.o: /home/petr/Documents/labs3sem/laba2/main.cpp
CMakeFiles/SortingApp.dir/main.cpp.o: CMakeFiles/SortingApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/petr/Documents/labs3sem/laba2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SortingApp.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SortingApp.dir/main.cpp.o -MF CMakeFiles/SortingApp.dir/main.cpp.o.d -o CMakeFiles/SortingApp.dir/main.cpp.o -c /home/petr/Documents/labs3sem/laba2/main.cpp

CMakeFiles/SortingApp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SortingApp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petr/Documents/labs3sem/laba2/main.cpp > CMakeFiles/SortingApp.dir/main.cpp.i

CMakeFiles/SortingApp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SortingApp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petr/Documents/labs3sem/laba2/main.cpp -o CMakeFiles/SortingApp.dir/main.cpp.s

CMakeFiles/SortingApp.dir/UI/UI.cpp.o: CMakeFiles/SortingApp.dir/flags.make
CMakeFiles/SortingApp.dir/UI/UI.cpp.o: /home/petr/Documents/labs3sem/laba2/UI/UI.cpp
CMakeFiles/SortingApp.dir/UI/UI.cpp.o: CMakeFiles/SortingApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/petr/Documents/labs3sem/laba2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SortingApp.dir/UI/UI.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SortingApp.dir/UI/UI.cpp.o -MF CMakeFiles/SortingApp.dir/UI/UI.cpp.o.d -o CMakeFiles/SortingApp.dir/UI/UI.cpp.o -c /home/petr/Documents/labs3sem/laba2/UI/UI.cpp

CMakeFiles/SortingApp.dir/UI/UI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SortingApp.dir/UI/UI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petr/Documents/labs3sem/laba2/UI/UI.cpp > CMakeFiles/SortingApp.dir/UI/UI.cpp.i

CMakeFiles/SortingApp.dir/UI/UI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SortingApp.dir/UI/UI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petr/Documents/labs3sem/laba2/UI/UI.cpp -o CMakeFiles/SortingApp.dir/UI/UI.cpp.s

# Object files for target SortingApp
SortingApp_OBJECTS = \
"CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/SortingApp.dir/main.cpp.o" \
"CMakeFiles/SortingApp.dir/UI/UI.cpp.o"

# External object files for target SortingApp
SortingApp_EXTERNAL_OBJECTS =

SortingApp: CMakeFiles/SortingApp.dir/SortingApp_autogen/mocs_compilation.cpp.o
SortingApp: CMakeFiles/SortingApp.dir/main.cpp.o
SortingApp: CMakeFiles/SortingApp.dir/UI/UI.cpp.o
SortingApp: CMakeFiles/SortingApp.dir/build.make
SortingApp: CMakeFiles/SortingApp.dir/compiler_depend.ts
SortingApp: /usr/lib/libQt6Widgets.so.6.8.0
SortingApp: /usr/lib/libQt6Gui.so.6.8.0
SortingApp: /usr/lib/libGLX.so
SortingApp: /usr/lib/libOpenGL.so
SortingApp: /usr/lib/libQt6Core.so.6.8.0
SortingApp: CMakeFiles/SortingApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/petr/Documents/labs3sem/laba2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable SortingApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SortingApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SortingApp.dir/build: SortingApp
.PHONY : CMakeFiles/SortingApp.dir/build

CMakeFiles/SortingApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SortingApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SortingApp.dir/clean

CMakeFiles/SortingApp.dir/depend: SortingApp_autogen/timestamp
	cd /home/petr/Documents/labs3sem/laba2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/petr/Documents/labs3sem/laba2 /home/petr/Documents/labs3sem/laba2 /home/petr/Documents/labs3sem/laba2/build /home/petr/Documents/labs3sem/laba2/build /home/petr/Documents/labs3sem/laba2/build/CMakeFiles/SortingApp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SortingApp.dir/depend

