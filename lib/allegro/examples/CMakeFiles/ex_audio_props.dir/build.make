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
include examples/CMakeFiles/ex_audio_props.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/ex_audio_props.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/ex_audio_props.dir/flags.make

examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o: examples/CMakeFiles/ex_audio_props.dir/flags.make
examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o: examples/ex_audio_props.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/damien/workspace/battlechess/lib/allegro/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o"
	cd /home/damien/workspace/battlechess/lib/allegro/examples && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o -c /home/damien/workspace/battlechess/lib/allegro/examples/ex_audio_props.cpp

examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.i"
	cd /home/damien/workspace/battlechess/lib/allegro/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/damien/workspace/battlechess/lib/allegro/examples/ex_audio_props.cpp > CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.i

examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.s"
	cd /home/damien/workspace/battlechess/lib/allegro/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/damien/workspace/battlechess/lib/allegro/examples/ex_audio_props.cpp -o CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.s

examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o.requires:
.PHONY : examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o.requires

examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o.provides: examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o.requires
	$(MAKE) -f examples/CMakeFiles/ex_audio_props.dir/build.make examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o.provides.build
.PHONY : examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o.provides

examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o.provides.build: examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o

examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.o: examples/CMakeFiles/ex_audio_props.dir/flags.make
examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.o: examples/nihgui.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/damien/workspace/battlechess/lib/allegro/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.o"
	cd /home/damien/workspace/battlechess/lib/allegro/examples && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ex_audio_props.dir/nihgui.cpp.o -c /home/damien/workspace/battlechess/lib/allegro/examples/nihgui.cpp

examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex_audio_props.dir/nihgui.cpp.i"
	cd /home/damien/workspace/battlechess/lib/allegro/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/damien/workspace/battlechess/lib/allegro/examples/nihgui.cpp > CMakeFiles/ex_audio_props.dir/nihgui.cpp.i

examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex_audio_props.dir/nihgui.cpp.s"
	cd /home/damien/workspace/battlechess/lib/allegro/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/damien/workspace/battlechess/lib/allegro/examples/nihgui.cpp -o CMakeFiles/ex_audio_props.dir/nihgui.cpp.s

examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.o.requires:
.PHONY : examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.o.requires

examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.o.provides: examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.o.requires
	$(MAKE) -f examples/CMakeFiles/ex_audio_props.dir/build.make examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.o.provides.build
.PHONY : examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.o.provides

examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.o.provides.build: examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.o

# Object files for target ex_audio_props
ex_audio_props_OBJECTS = \
"CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o" \
"CMakeFiles/ex_audio_props.dir/nihgui.cpp.o"

# External object files for target ex_audio_props
ex_audio_props_EXTERNAL_OBJECTS =

examples/ex_audio_props: examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o
examples/ex_audio_props: examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.o
examples/ex_audio_props: lib/liballegro_font.so.5.0.7
examples/ex_audio_props: lib/liballegro_primitives.so.5.0.7
examples/ex_audio_props: lib/liballegro_image.so.5.0.7
examples/ex_audio_props: lib/liballegro_audio.so.5.0.7
examples/ex_audio_props: lib/liballegro_acodec.so.5.0.7
examples/ex_audio_props: lib/liballegro.so.5.0.7
examples/ex_audio_props: lib/liballegro_main.so.5.0.7
examples/ex_audio_props: lib/liballegro_dialog.so.5.0.7
examples/ex_audio_props: /usr/lib/libpng.so
examples/ex_audio_props: /usr/lib/libz.so
examples/ex_audio_props: /usr/lib/libjpeg.so
examples/ex_audio_props: lib/liballegro_audio.so.5.0.7
examples/ex_audio_props: /usr/lib/libopenal.so
examples/ex_audio_props: /usr/lib/libFLAC.so
examples/ex_audio_props: /usr/lib/libogg.so
examples/ex_audio_props: /usr/lib/libvorbisfile.so
examples/ex_audio_props: /usr/lib/libvorbis.so
examples/ex_audio_props: /usr/lib/libogg.so
examples/ex_audio_props: /usr/lib/libvorbisfile.so
examples/ex_audio_props: /usr/lib/libvorbis.so
examples/ex_audio_props: lib/liballegro.so.5.0.7
examples/ex_audio_props: /usr/lib/libSM.so
examples/ex_audio_props: /usr/lib/libICE.so
examples/ex_audio_props: /usr/lib/libX11.so
examples/ex_audio_props: /usr/lib/libXext.so
examples/ex_audio_props: /usr/lib/libGL.so
examples/ex_audio_props: /usr/lib/libGLU.so
examples/ex_audio_props: examples/CMakeFiles/ex_audio_props.dir/build.make
examples/ex_audio_props: examples/CMakeFiles/ex_audio_props.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ex_audio_props"
	cd /home/damien/workspace/battlechess/lib/allegro/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex_audio_props.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/ex_audio_props.dir/build: examples/ex_audio_props
.PHONY : examples/CMakeFiles/ex_audio_props.dir/build

examples/CMakeFiles/ex_audio_props.dir/requires: examples/CMakeFiles/ex_audio_props.dir/ex_audio_props.cpp.o.requires
examples/CMakeFiles/ex_audio_props.dir/requires: examples/CMakeFiles/ex_audio_props.dir/nihgui.cpp.o.requires
.PHONY : examples/CMakeFiles/ex_audio_props.dir/requires

examples/CMakeFiles/ex_audio_props.dir/clean:
	cd /home/damien/workspace/battlechess/lib/allegro/examples && $(CMAKE_COMMAND) -P CMakeFiles/ex_audio_props.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/ex_audio_props.dir/clean

examples/CMakeFiles/ex_audio_props.dir/depend:
	cd /home/damien/workspace/battlechess/lib/allegro && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/damien/workspace/battlechess/lib/allegro /home/damien/workspace/battlechess/lib/allegro/examples /home/damien/workspace/battlechess/lib/allegro /home/damien/workspace/battlechess/lib/allegro/examples /home/damien/workspace/battlechess/lib/allegro/examples/CMakeFiles/ex_audio_props.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/ex_audio_props.dir/depend

