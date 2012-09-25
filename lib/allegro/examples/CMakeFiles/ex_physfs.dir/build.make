# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/damien/workspace/battlechess/lib/allegro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/damien/workspace/battlechess/lib/allegro

# Include any dependencies generated for this target.
include examples/CMakeFiles/ex_physfs.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/ex_physfs.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/ex_physfs.dir/flags.make

examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.o: examples/CMakeFiles/ex_physfs.dir/flags.make
examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.o: examples/ex_physfs.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/damien/workspace/battlechess/lib/allegro/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.o"
	cd /home/damien/workspace/battlechess/lib/allegro/examples && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ex_physfs.dir/ex_physfs.c.o   -c /home/damien/workspace/battlechess/lib/allegro/examples/ex_physfs.c

examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ex_physfs.dir/ex_physfs.c.i"
	cd /home/damien/workspace/battlechess/lib/allegro/examples && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/damien/workspace/battlechess/lib/allegro/examples/ex_physfs.c > CMakeFiles/ex_physfs.dir/ex_physfs.c.i

examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ex_physfs.dir/ex_physfs.c.s"
	cd /home/damien/workspace/battlechess/lib/allegro/examples && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/damien/workspace/battlechess/lib/allegro/examples/ex_physfs.c -o CMakeFiles/ex_physfs.dir/ex_physfs.c.s

examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.o.requires:
.PHONY : examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.o.requires

examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.o.provides: examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.o.requires
	$(MAKE) -f examples/CMakeFiles/ex_physfs.dir/build.make examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.o.provides.build
.PHONY : examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.o.provides

examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.o.provides.build: examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.o

# Object files for target ex_physfs
ex_physfs_OBJECTS = \
"CMakeFiles/ex_physfs.dir/ex_physfs.c.o"

# External object files for target ex_physfs
ex_physfs_EXTERNAL_OBJECTS =

examples/ex_physfs: examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.o
examples/ex_physfs: lib/liballegro_physfs.so.5.0.7
examples/ex_physfs: lib/liballegro_image.so.5.0.7
examples/ex_physfs: lib/liballegro.so.5.0.7
examples/ex_physfs: lib/liballegro_main.so.5.0.7
examples/ex_physfs: lib/liballegro_dialog.so.5.0.7
examples/ex_physfs: /usr/lib/libphysfs.so
examples/ex_physfs: /usr/lib/libpng.so
examples/ex_physfs: /usr/lib/libz.so
examples/ex_physfs: /usr/lib/libjpeg.so
examples/ex_physfs: lib/liballegro.so.5.0.7
examples/ex_physfs: /usr/lib/libSM.so
examples/ex_physfs: /usr/lib/libICE.so
examples/ex_physfs: /usr/lib/libX11.so
examples/ex_physfs: /usr/lib/libXext.so
examples/ex_physfs: /usr/lib/libGL.so
examples/ex_physfs: /usr/lib/libGLU.so
examples/ex_physfs: examples/CMakeFiles/ex_physfs.dir/build.make
examples/ex_physfs: examples/CMakeFiles/ex_physfs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ex_physfs"
	cd /home/damien/workspace/battlechess/lib/allegro/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex_physfs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/ex_physfs.dir/build: examples/ex_physfs
.PHONY : examples/CMakeFiles/ex_physfs.dir/build

examples/CMakeFiles/ex_physfs.dir/requires: examples/CMakeFiles/ex_physfs.dir/ex_physfs.c.o.requires
.PHONY : examples/CMakeFiles/ex_physfs.dir/requires

examples/CMakeFiles/ex_physfs.dir/clean:
	cd /home/damien/workspace/battlechess/lib/allegro/examples && $(CMAKE_COMMAND) -P CMakeFiles/ex_physfs.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/ex_physfs.dir/clean

examples/CMakeFiles/ex_physfs.dir/depend:
	cd /home/damien/workspace/battlechess/lib/allegro && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/damien/workspace/battlechess/lib/allegro /home/damien/workspace/battlechess/lib/allegro/examples /home/damien/workspace/battlechess/lib/allegro /home/damien/workspace/battlechess/lib/allegro/examples /home/damien/workspace/battlechess/lib/allegro/examples/CMakeFiles/ex_physfs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/ex_physfs.dir/depend

