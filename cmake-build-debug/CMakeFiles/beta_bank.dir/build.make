# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
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
CMAKE_SOURCE_DIR = "/Users/yusufkocaturk/CLionProjects/Beta Bank/beta_bank"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/yusufkocaturk/CLionProjects/Beta Bank/beta_bank/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/beta_bank.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/beta_bank.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/beta_bank.dir/flags.make

CMakeFiles/beta_bank.dir/main.c.o: CMakeFiles/beta_bank.dir/flags.make
CMakeFiles/beta_bank.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/yusufkocaturk/CLionProjects/Beta Bank/beta_bank/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/beta_bank.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/beta_bank.dir/main.c.o   -c "/Users/yusufkocaturk/CLionProjects/Beta Bank/beta_bank/main.c"

CMakeFiles/beta_bank.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/beta_bank.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/yusufkocaturk/CLionProjects/Beta Bank/beta_bank/main.c" > CMakeFiles/beta_bank.dir/main.c.i

CMakeFiles/beta_bank.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/beta_bank.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/yusufkocaturk/CLionProjects/Beta Bank/beta_bank/main.c" -o CMakeFiles/beta_bank.dir/main.c.s

# Object files for target beta_bank
beta_bank_OBJECTS = \
"CMakeFiles/beta_bank.dir/main.c.o"

# External object files for target beta_bank
beta_bank_EXTERNAL_OBJECTS =

beta_bank: CMakeFiles/beta_bank.dir/main.c.o
beta_bank: CMakeFiles/beta_bank.dir/build.make
beta_bank: CMakeFiles/beta_bank.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/yusufkocaturk/CLionProjects/Beta Bank/beta_bank/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable beta_bank"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/beta_bank.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/beta_bank.dir/build: beta_bank

.PHONY : CMakeFiles/beta_bank.dir/build

CMakeFiles/beta_bank.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/beta_bank.dir/cmake_clean.cmake
.PHONY : CMakeFiles/beta_bank.dir/clean

CMakeFiles/beta_bank.dir/depend:
	cd "/Users/yusufkocaturk/CLionProjects/Beta Bank/beta_bank/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/yusufkocaturk/CLionProjects/Beta Bank/beta_bank" "/Users/yusufkocaturk/CLionProjects/Beta Bank/beta_bank" "/Users/yusufkocaturk/CLionProjects/Beta Bank/beta_bank/cmake-build-debug" "/Users/yusufkocaturk/CLionProjects/Beta Bank/beta_bank/cmake-build-debug" "/Users/yusufkocaturk/CLionProjects/Beta Bank/beta_bank/cmake-build-debug/CMakeFiles/beta_bank.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/beta_bank.dir/depend

