# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.29.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.29.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chan/Desktop/StaticScript-master-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chan/Desktop/StaticScript-master-2

# Include any dependencies generated for this target.
include src/Entity/CMakeFiles/entity.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Entity/CMakeFiles/entity.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Entity/CMakeFiles/entity.dir/progress.make

# Include the compile flags for this target's objects.
include src/Entity/CMakeFiles/entity.dir/flags.make

src/Entity/CMakeFiles/entity.dir/Type.cpp.o: src/Entity/CMakeFiles/entity.dir/flags.make
src/Entity/CMakeFiles/entity.dir/Type.cpp.o: src/Entity/Type.cpp
src/Entity/CMakeFiles/entity.dir/Type.cpp.o: src/Entity/CMakeFiles/entity.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Entity/CMakeFiles/entity.dir/Type.cpp.o"
	cd /Users/chan/Desktop/StaticScript-master-2/src/Entity && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Entity/CMakeFiles/entity.dir/Type.cpp.o -MF CMakeFiles/entity.dir/Type.cpp.o.d -o CMakeFiles/entity.dir/Type.cpp.o -c /Users/chan/Desktop/StaticScript-master-2/src/Entity/Type.cpp

src/Entity/CMakeFiles/entity.dir/Type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/entity.dir/Type.cpp.i"
	cd /Users/chan/Desktop/StaticScript-master-2/src/Entity && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/Desktop/StaticScript-master-2/src/Entity/Type.cpp > CMakeFiles/entity.dir/Type.cpp.i

src/Entity/CMakeFiles/entity.dir/Type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/entity.dir/Type.cpp.s"
	cd /Users/chan/Desktop/StaticScript-master-2/src/Entity && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/Desktop/StaticScript-master-2/src/Entity/Type.cpp -o CMakeFiles/entity.dir/Type.cpp.s

src/Entity/CMakeFiles/entity.dir/Scope.cpp.o: src/Entity/CMakeFiles/entity.dir/flags.make
src/Entity/CMakeFiles/entity.dir/Scope.cpp.o: src/Entity/Scope.cpp
src/Entity/CMakeFiles/entity.dir/Scope.cpp.o: src/Entity/CMakeFiles/entity.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/Entity/CMakeFiles/entity.dir/Scope.cpp.o"
	cd /Users/chan/Desktop/StaticScript-master-2/src/Entity && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Entity/CMakeFiles/entity.dir/Scope.cpp.o -MF CMakeFiles/entity.dir/Scope.cpp.o.d -o CMakeFiles/entity.dir/Scope.cpp.o -c /Users/chan/Desktop/StaticScript-master-2/src/Entity/Scope.cpp

src/Entity/CMakeFiles/entity.dir/Scope.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/entity.dir/Scope.cpp.i"
	cd /Users/chan/Desktop/StaticScript-master-2/src/Entity && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/Desktop/StaticScript-master-2/src/Entity/Scope.cpp > CMakeFiles/entity.dir/Scope.cpp.i

src/Entity/CMakeFiles/entity.dir/Scope.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/entity.dir/Scope.cpp.s"
	cd /Users/chan/Desktop/StaticScript-master-2/src/Entity && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/Desktop/StaticScript-master-2/src/Entity/Scope.cpp -o CMakeFiles/entity.dir/Scope.cpp.s

entity: src/Entity/CMakeFiles/entity.dir/Type.cpp.o
entity: src/Entity/CMakeFiles/entity.dir/Scope.cpp.o
entity: src/Entity/CMakeFiles/entity.dir/build.make
.PHONY : entity

# Rule to build all files generated by this target.
src/Entity/CMakeFiles/entity.dir/build: entity
.PHONY : src/Entity/CMakeFiles/entity.dir/build

src/Entity/CMakeFiles/entity.dir/clean:
	cd /Users/chan/Desktop/StaticScript-master-2/src/Entity && $(CMAKE_COMMAND) -P CMakeFiles/entity.dir/cmake_clean.cmake
.PHONY : src/Entity/CMakeFiles/entity.dir/clean

src/Entity/CMakeFiles/entity.dir/depend:
	cd /Users/chan/Desktop/StaticScript-master-2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chan/Desktop/StaticScript-master-2 /Users/chan/Desktop/StaticScript-master-2/src/Entity /Users/chan/Desktop/StaticScript-master-2 /Users/chan/Desktop/StaticScript-master-2/src/Entity /Users/chan/Desktop/StaticScript-master-2/src/Entity/CMakeFiles/entity.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/Entity/CMakeFiles/entity.dir/depend

