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
include src/CodeGen/CMakeFiles/codegen.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CodeGen/CMakeFiles/codegen.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CodeGen/CMakeFiles/codegen.dir/progress.make

# Include the compile flags for this target's objects.
include src/CodeGen/CMakeFiles/codegen.dir/flags.make

src/CodeGen/CMakeFiles/codegen.dir/Builtin.cpp.o: src/CodeGen/CMakeFiles/codegen.dir/flags.make
src/CodeGen/CMakeFiles/codegen.dir/Builtin.cpp.o: src/CodeGen/Builtin.cpp
src/CodeGen/CMakeFiles/codegen.dir/Builtin.cpp.o: src/CodeGen/CMakeFiles/codegen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CodeGen/CMakeFiles/codegen.dir/Builtin.cpp.o"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CodeGen/CMakeFiles/codegen.dir/Builtin.cpp.o -MF CMakeFiles/codegen.dir/Builtin.cpp.o.d -o CMakeFiles/codegen.dir/Builtin.cpp.o -c /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/Builtin.cpp

src/CodeGen/CMakeFiles/codegen.dir/Builtin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/codegen.dir/Builtin.cpp.i"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/Builtin.cpp > CMakeFiles/codegen.dir/Builtin.cpp.i

src/CodeGen/CMakeFiles/codegen.dir/Builtin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/codegen.dir/Builtin.cpp.s"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/Builtin.cpp -o CMakeFiles/codegen.dir/Builtin.cpp.s

src/CodeGen/CMakeFiles/codegen.dir/IRGenerator.cpp.o: src/CodeGen/CMakeFiles/codegen.dir/flags.make
src/CodeGen/CMakeFiles/codegen.dir/IRGenerator.cpp.o: src/CodeGen/IRGenerator.cpp
src/CodeGen/CMakeFiles/codegen.dir/IRGenerator.cpp.o: src/CodeGen/CMakeFiles/codegen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CodeGen/CMakeFiles/codegen.dir/IRGenerator.cpp.o"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CodeGen/CMakeFiles/codegen.dir/IRGenerator.cpp.o -MF CMakeFiles/codegen.dir/IRGenerator.cpp.o.d -o CMakeFiles/codegen.dir/IRGenerator.cpp.o -c /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/IRGenerator.cpp

src/CodeGen/CMakeFiles/codegen.dir/IRGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/codegen.dir/IRGenerator.cpp.i"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/IRGenerator.cpp > CMakeFiles/codegen.dir/IRGenerator.cpp.i

src/CodeGen/CMakeFiles/codegen.dir/IRGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/codegen.dir/IRGenerator.cpp.s"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/IRGenerator.cpp -o CMakeFiles/codegen.dir/IRGenerator.cpp.s

src/CodeGen/CMakeFiles/codegen.dir/DeclCodeGen.cpp.o: src/CodeGen/CMakeFiles/codegen.dir/flags.make
src/CodeGen/CMakeFiles/codegen.dir/DeclCodeGen.cpp.o: src/CodeGen/DeclCodeGen.cpp
src/CodeGen/CMakeFiles/codegen.dir/DeclCodeGen.cpp.o: src/CodeGen/CMakeFiles/codegen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CodeGen/CMakeFiles/codegen.dir/DeclCodeGen.cpp.o"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CodeGen/CMakeFiles/codegen.dir/DeclCodeGen.cpp.o -MF CMakeFiles/codegen.dir/DeclCodeGen.cpp.o.d -o CMakeFiles/codegen.dir/DeclCodeGen.cpp.o -c /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/DeclCodeGen.cpp

src/CodeGen/CMakeFiles/codegen.dir/DeclCodeGen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/codegen.dir/DeclCodeGen.cpp.i"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/DeclCodeGen.cpp > CMakeFiles/codegen.dir/DeclCodeGen.cpp.i

src/CodeGen/CMakeFiles/codegen.dir/DeclCodeGen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/codegen.dir/DeclCodeGen.cpp.s"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/DeclCodeGen.cpp -o CMakeFiles/codegen.dir/DeclCodeGen.cpp.s

src/CodeGen/CMakeFiles/codegen.dir/ExprCodeGen.cpp.o: src/CodeGen/CMakeFiles/codegen.dir/flags.make
src/CodeGen/CMakeFiles/codegen.dir/ExprCodeGen.cpp.o: src/CodeGen/ExprCodeGen.cpp
src/CodeGen/CMakeFiles/codegen.dir/ExprCodeGen.cpp.o: src/CodeGen/CMakeFiles/codegen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CodeGen/CMakeFiles/codegen.dir/ExprCodeGen.cpp.o"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CodeGen/CMakeFiles/codegen.dir/ExprCodeGen.cpp.o -MF CMakeFiles/codegen.dir/ExprCodeGen.cpp.o.d -o CMakeFiles/codegen.dir/ExprCodeGen.cpp.o -c /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/ExprCodeGen.cpp

src/CodeGen/CMakeFiles/codegen.dir/ExprCodeGen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/codegen.dir/ExprCodeGen.cpp.i"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/ExprCodeGen.cpp > CMakeFiles/codegen.dir/ExprCodeGen.cpp.i

src/CodeGen/CMakeFiles/codegen.dir/ExprCodeGen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/codegen.dir/ExprCodeGen.cpp.s"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/ExprCodeGen.cpp -o CMakeFiles/codegen.dir/ExprCodeGen.cpp.s

src/CodeGen/CMakeFiles/codegen.dir/StmtCodeGen.cpp.o: src/CodeGen/CMakeFiles/codegen.dir/flags.make
src/CodeGen/CMakeFiles/codegen.dir/StmtCodeGen.cpp.o: src/CodeGen/StmtCodeGen.cpp
src/CodeGen/CMakeFiles/codegen.dir/StmtCodeGen.cpp.o: src/CodeGen/CMakeFiles/codegen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CodeGen/CMakeFiles/codegen.dir/StmtCodeGen.cpp.o"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CodeGen/CMakeFiles/codegen.dir/StmtCodeGen.cpp.o -MF CMakeFiles/codegen.dir/StmtCodeGen.cpp.o.d -o CMakeFiles/codegen.dir/StmtCodeGen.cpp.o -c /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/StmtCodeGen.cpp

src/CodeGen/CMakeFiles/codegen.dir/StmtCodeGen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/codegen.dir/StmtCodeGen.cpp.i"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/StmtCodeGen.cpp > CMakeFiles/codegen.dir/StmtCodeGen.cpp.i

src/CodeGen/CMakeFiles/codegen.dir/StmtCodeGen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/codegen.dir/StmtCodeGen.cpp.s"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/StmtCodeGen.cpp -o CMakeFiles/codegen.dir/StmtCodeGen.cpp.s

src/CodeGen/CMakeFiles/codegen.dir/Pass.cpp.o: src/CodeGen/CMakeFiles/codegen.dir/flags.make
src/CodeGen/CMakeFiles/codegen.dir/Pass.cpp.o: src/CodeGen/Pass.cpp
src/CodeGen/CMakeFiles/codegen.dir/Pass.cpp.o: src/CodeGen/CMakeFiles/codegen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CodeGen/CMakeFiles/codegen.dir/Pass.cpp.o"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CodeGen/CMakeFiles/codegen.dir/Pass.cpp.o -MF CMakeFiles/codegen.dir/Pass.cpp.o.d -o CMakeFiles/codegen.dir/Pass.cpp.o -c /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/Pass.cpp

src/CodeGen/CMakeFiles/codegen.dir/Pass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/codegen.dir/Pass.cpp.i"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/Pass.cpp > CMakeFiles/codegen.dir/Pass.cpp.i

src/CodeGen/CMakeFiles/codegen.dir/Pass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/codegen.dir/Pass.cpp.s"
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/Pass.cpp -o CMakeFiles/codegen.dir/Pass.cpp.s

codegen: src/CodeGen/CMakeFiles/codegen.dir/Builtin.cpp.o
codegen: src/CodeGen/CMakeFiles/codegen.dir/IRGenerator.cpp.o
codegen: src/CodeGen/CMakeFiles/codegen.dir/DeclCodeGen.cpp.o
codegen: src/CodeGen/CMakeFiles/codegen.dir/ExprCodeGen.cpp.o
codegen: src/CodeGen/CMakeFiles/codegen.dir/StmtCodeGen.cpp.o
codegen: src/CodeGen/CMakeFiles/codegen.dir/Pass.cpp.o
codegen: src/CodeGen/CMakeFiles/codegen.dir/build.make
.PHONY : codegen

# Rule to build all files generated by this target.
src/CodeGen/CMakeFiles/codegen.dir/build: codegen
.PHONY : src/CodeGen/CMakeFiles/codegen.dir/build

src/CodeGen/CMakeFiles/codegen.dir/clean:
	cd /Users/chan/Desktop/StaticScript-master-2/src/CodeGen && $(CMAKE_COMMAND) -P CMakeFiles/codegen.dir/cmake_clean.cmake
.PHONY : src/CodeGen/CMakeFiles/codegen.dir/clean

src/CodeGen/CMakeFiles/codegen.dir/depend:
	cd /Users/chan/Desktop/StaticScript-master-2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chan/Desktop/StaticScript-master-2 /Users/chan/Desktop/StaticScript-master-2/src/CodeGen /Users/chan/Desktop/StaticScript-master-2 /Users/chan/Desktop/StaticScript-master-2/src/CodeGen /Users/chan/Desktop/StaticScript-master-2/src/CodeGen/CMakeFiles/codegen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CodeGen/CMakeFiles/codegen.dir/depend

