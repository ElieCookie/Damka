# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Damka_Project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Damka_Project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Damka_Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Damka_Project.dir/flags.make

CMakeFiles/Damka_Project.dir/game.c.o: CMakeFiles/Damka_Project.dir/flags.make
CMakeFiles/Damka_Project.dir/game.c.o: /Users/lidorlevi/Desktop/MTA/Advanced\ C\ Project/Damka/game.c
CMakeFiles/Damka_Project.dir/game.c.o: CMakeFiles/Damka_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Damka_Project.dir/game.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Damka_Project.dir/game.c.o -MF CMakeFiles/Damka_Project.dir/game.c.o.d -o CMakeFiles/Damka_Project.dir/game.c.o -c "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/game.c"

CMakeFiles/Damka_Project.dir/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Damka_Project.dir/game.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/game.c" > CMakeFiles/Damka_Project.dir/game.c.i

CMakeFiles/Damka_Project.dir/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Damka_Project.dir/game.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/game.c" -o CMakeFiles/Damka_Project.dir/game.c.s

CMakeFiles/Damka_Project.dir/general.c.o: CMakeFiles/Damka_Project.dir/flags.make
CMakeFiles/Damka_Project.dir/general.c.o: /Users/lidorlevi/Desktop/MTA/Advanced\ C\ Project/Damka/general.c
CMakeFiles/Damka_Project.dir/general.c.o: CMakeFiles/Damka_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Damka_Project.dir/general.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Damka_Project.dir/general.c.o -MF CMakeFiles/Damka_Project.dir/general.c.o.d -o CMakeFiles/Damka_Project.dir/general.c.o -c "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/general.c"

CMakeFiles/Damka_Project.dir/general.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Damka_Project.dir/general.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/general.c" > CMakeFiles/Damka_Project.dir/general.c.i

CMakeFiles/Damka_Project.dir/general.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Damka_Project.dir/general.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/general.c" -o CMakeFiles/Damka_Project.dir/general.c.s

CMakeFiles/Damka_Project.dir/general_settings.c.o: CMakeFiles/Damka_Project.dir/flags.make
CMakeFiles/Damka_Project.dir/general_settings.c.o: /Users/lidorlevi/Desktop/MTA/Advanced\ C\ Project/Damka/general_settings.c
CMakeFiles/Damka_Project.dir/general_settings.c.o: CMakeFiles/Damka_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Damka_Project.dir/general_settings.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Damka_Project.dir/general_settings.c.o -MF CMakeFiles/Damka_Project.dir/general_settings.c.o.d -o CMakeFiles/Damka_Project.dir/general_settings.c.o -c "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/general_settings.c"

CMakeFiles/Damka_Project.dir/general_settings.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Damka_Project.dir/general_settings.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/general_settings.c" > CMakeFiles/Damka_Project.dir/general_settings.c.i

CMakeFiles/Damka_Project.dir/general_settings.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Damka_Project.dir/general_settings.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/general_settings.c" -o CMakeFiles/Damka_Project.dir/general_settings.c.s

CMakeFiles/Damka_Project.dir/q1.c.o: CMakeFiles/Damka_Project.dir/flags.make
CMakeFiles/Damka_Project.dir/q1.c.o: /Users/lidorlevi/Desktop/MTA/Advanced\ C\ Project/Damka/q1.c
CMakeFiles/Damka_Project.dir/q1.c.o: CMakeFiles/Damka_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Damka_Project.dir/q1.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Damka_Project.dir/q1.c.o -MF CMakeFiles/Damka_Project.dir/q1.c.o.d -o CMakeFiles/Damka_Project.dir/q1.c.o -c "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/q1.c"

CMakeFiles/Damka_Project.dir/q1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Damka_Project.dir/q1.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/q1.c" > CMakeFiles/Damka_Project.dir/q1.c.i

CMakeFiles/Damka_Project.dir/q1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Damka_Project.dir/q1.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/q1.c" -o CMakeFiles/Damka_Project.dir/q1.c.s

CMakeFiles/Damka_Project.dir/q3.c.o: CMakeFiles/Damka_Project.dir/flags.make
CMakeFiles/Damka_Project.dir/q3.c.o: /Users/lidorlevi/Desktop/MTA/Advanced\ C\ Project/Damka/q3.c
CMakeFiles/Damka_Project.dir/q3.c.o: CMakeFiles/Damka_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Damka_Project.dir/q3.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Damka_Project.dir/q3.c.o -MF CMakeFiles/Damka_Project.dir/q3.c.o.d -o CMakeFiles/Damka_Project.dir/q3.c.o -c "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/q3.c"

CMakeFiles/Damka_Project.dir/q3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Damka_Project.dir/q3.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/q3.c" > CMakeFiles/Damka_Project.dir/q3.c.i

CMakeFiles/Damka_Project.dir/q3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Damka_Project.dir/q3.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/q3.c" -o CMakeFiles/Damka_Project.dir/q3.c.s

CMakeFiles/Damka_Project.dir/q2.c.o: CMakeFiles/Damka_Project.dir/flags.make
CMakeFiles/Damka_Project.dir/q2.c.o: /Users/lidorlevi/Desktop/MTA/Advanced\ C\ Project/Damka/q2.c
CMakeFiles/Damka_Project.dir/q2.c.o: CMakeFiles/Damka_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Damka_Project.dir/q2.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Damka_Project.dir/q2.c.o -MF CMakeFiles/Damka_Project.dir/q2.c.o.d -o CMakeFiles/Damka_Project.dir/q2.c.o -c "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/q2.c"

CMakeFiles/Damka_Project.dir/q2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Damka_Project.dir/q2.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/q2.c" > CMakeFiles/Damka_Project.dir/q2.c.i

CMakeFiles/Damka_Project.dir/q2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Damka_Project.dir/q2.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/q2.c" -o CMakeFiles/Damka_Project.dir/q2.c.s

CMakeFiles/Damka_Project.dir/q4.c.o: CMakeFiles/Damka_Project.dir/flags.make
CMakeFiles/Damka_Project.dir/q4.c.o: /Users/lidorlevi/Desktop/MTA/Advanced\ C\ Project/Damka/q4.c
CMakeFiles/Damka_Project.dir/q4.c.o: CMakeFiles/Damka_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Damka_Project.dir/q4.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Damka_Project.dir/q4.c.o -MF CMakeFiles/Damka_Project.dir/q4.c.o.d -o CMakeFiles/Damka_Project.dir/q4.c.o -c "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/q4.c"

CMakeFiles/Damka_Project.dir/q4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Damka_Project.dir/q4.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/q4.c" > CMakeFiles/Damka_Project.dir/q4.c.i

CMakeFiles/Damka_Project.dir/q4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Damka_Project.dir/q4.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/q4.c" -o CMakeFiles/Damka_Project.dir/q4.c.s

# Object files for target Damka_Project
Damka_Project_OBJECTS = \
"CMakeFiles/Damka_Project.dir/game.c.o" \
"CMakeFiles/Damka_Project.dir/general.c.o" \
"CMakeFiles/Damka_Project.dir/general_settings.c.o" \
"CMakeFiles/Damka_Project.dir/q1.c.o" \
"CMakeFiles/Damka_Project.dir/q3.c.o" \
"CMakeFiles/Damka_Project.dir/q2.c.o" \
"CMakeFiles/Damka_Project.dir/q4.c.o"

# External object files for target Damka_Project
Damka_Project_EXTERNAL_OBJECTS =

Damka_Project: CMakeFiles/Damka_Project.dir/game.c.o
Damka_Project: CMakeFiles/Damka_Project.dir/general.c.o
Damka_Project: CMakeFiles/Damka_Project.dir/general_settings.c.o
Damka_Project: CMakeFiles/Damka_Project.dir/q1.c.o
Damka_Project: CMakeFiles/Damka_Project.dir/q3.c.o
Damka_Project: CMakeFiles/Damka_Project.dir/q2.c.o
Damka_Project: CMakeFiles/Damka_Project.dir/q4.c.o
Damka_Project: CMakeFiles/Damka_Project.dir/build.make
Damka_Project: CMakeFiles/Damka_Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable Damka_Project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Damka_Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Damka_Project.dir/build: Damka_Project
.PHONY : CMakeFiles/Damka_Project.dir/build

CMakeFiles/Damka_Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Damka_Project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Damka_Project.dir/clean

CMakeFiles/Damka_Project.dir/depend:
	cd "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka" "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka" "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/cmake-build-debug" "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/cmake-build-debug" "/Users/lidorlevi/Desktop/MTA/Advanced C Project/Damka/cmake-build-debug/CMakeFiles/Damka_Project.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Damka_Project.dir/depend

