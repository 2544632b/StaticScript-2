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
include CMakeFiles/parser.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/parser.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parser.dir/flags.make

antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.tokens: grammar/StaticScriptLexer.g4
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.tokens, antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.interp, antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.h, antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp"
	/usr/local/Cellar/cmake/3.29.3/bin/cmake -E remove_directory /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptLexer
	/usr/local/Cellar/cmake/3.29.3/bin/cmake -E make_directory /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptLexer
	/Library/Java/JavaVirtualMachines/graalvm-jdk-22.0.1+8.1/Contents/Home/bin/java -jar /usr/local/Cellar/antlr/4.9.2/antlr-4.9.2-complete.jar -Werror -Dlanguage=Cpp -no-listener -no-visitor -o /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptLexer /Users/chan/Desktop/StaticScript-master-2/grammar/StaticScriptLexer.g4

antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.interp: antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.tokens
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.interp

antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.h: antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.tokens
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.h

antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp: antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.tokens
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp

antlr4_generated_src/StaticScriptParser/StaticScriptParser.tokens: grammar/StaticScriptParser.g4
antlr4_generated_src/StaticScriptParser/StaticScriptParser.tokens: antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.tokens
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating antlr4_generated_src/StaticScriptParser/StaticScriptParser.tokens, antlr4_generated_src/StaticScriptParser/StaticScriptParser.interp, antlr4_generated_src/StaticScriptParser/StaticScriptParser.h, antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp, antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.h, antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp, antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.h, antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp"
	/usr/local/Cellar/cmake/3.29.3/bin/cmake -E remove_directory /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptParser
	/usr/local/Cellar/cmake/3.29.3/bin/cmake -E make_directory /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptParser
	/Library/Java/JavaVirtualMachines/graalvm-jdk-22.0.1+8.1/Contents/Home/bin/java -jar /usr/local/Cellar/antlr/4.9.2/antlr-4.9.2-complete.jar -Werror -Dlanguage=Cpp -no-listener -visitor -lib /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptLexer -o /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptParser /Users/chan/Desktop/StaticScript-master-2/grammar/StaticScriptParser.g4

antlr4_generated_src/StaticScriptParser/StaticScriptParser.interp: antlr4_generated_src/StaticScriptParser/StaticScriptParser.tokens
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4_generated_src/StaticScriptParser/StaticScriptParser.interp

antlr4_generated_src/StaticScriptParser/StaticScriptParser.h: antlr4_generated_src/StaticScriptParser/StaticScriptParser.tokens
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4_generated_src/StaticScriptParser/StaticScriptParser.h

antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp: antlr4_generated_src/StaticScriptParser/StaticScriptParser.tokens
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp

antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.h: antlr4_generated_src/StaticScriptParser/StaticScriptParser.tokens
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.h

antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp: antlr4_generated_src/StaticScriptParser/StaticScriptParser.tokens
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp

antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.h: antlr4_generated_src/StaticScriptParser/StaticScriptParser.tokens
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.h

antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp: antlr4_generated_src/StaticScriptParser/StaticScriptParser.tokens
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp

CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.o: antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp
CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.o: CMakeFiles/parser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -MD -MT CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.o -MF CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.o.d -o CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.o -c /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp

CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -E /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp > CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.i

CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -S /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp -o CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.s

CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.o: antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp
CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.o: CMakeFiles/parser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -MD -MT CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.o -MF CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.o.d -o CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.o -c /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp

CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -E /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp > CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.i

CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -S /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp -o CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.s

CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.o: antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp
CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.o: CMakeFiles/parser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -MD -MT CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.o -MF CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.o.d -o CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.o -c /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp

CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -E /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp > CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.i

CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -S /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp -o CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.s

CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.o: antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp
CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.o: CMakeFiles/parser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -MD -MT CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.o -MF CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.o.d -o CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.o -c /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp

CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -E /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp > CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.i

CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Wno-overloaded-virtual -S /Users/chan/Desktop/StaticScript-master-2/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp -o CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.s

parser: CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.o
parser: CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.o
parser: CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.o
parser: CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.o
parser: CMakeFiles/parser.dir/build.make
.PHONY : parser

# Rule to build all files generated by this target.
CMakeFiles/parser.dir/build: parser
.PHONY : CMakeFiles/parser.dir/build

CMakeFiles/parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parser.dir/clean

CMakeFiles/parser.dir/depend: antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp
CMakeFiles/parser.dir/depend: antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.h
CMakeFiles/parser.dir/depend: antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.interp
CMakeFiles/parser.dir/depend: antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.tokens
CMakeFiles/parser.dir/depend: antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp
CMakeFiles/parser.dir/depend: antlr4_generated_src/StaticScriptParser/StaticScriptParser.h
CMakeFiles/parser.dir/depend: antlr4_generated_src/StaticScriptParser/StaticScriptParser.interp
CMakeFiles/parser.dir/depend: antlr4_generated_src/StaticScriptParser/StaticScriptParser.tokens
CMakeFiles/parser.dir/depend: antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp
CMakeFiles/parser.dir/depend: antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.h
CMakeFiles/parser.dir/depend: antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp
CMakeFiles/parser.dir/depend: antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.h
	cd /Users/chan/Desktop/StaticScript-master-2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chan/Desktop/StaticScript-master-2 /Users/chan/Desktop/StaticScript-master-2 /Users/chan/Desktop/StaticScript-master-2 /Users/chan/Desktop/StaticScript-master-2 /Users/chan/Desktop/StaticScript-master-2/CMakeFiles/parser.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/parser.dir/depend

