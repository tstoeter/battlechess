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
include addons/acodec/CMakeFiles/allegro_acodec.dir/depend.make

# Include the progress variables for this target.
include addons/acodec/CMakeFiles/allegro_acodec.dir/progress.make

# Include the compile flags for this target's objects.
include addons/acodec/CMakeFiles/allegro_acodec.dir/flags.make

addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o: addons/acodec/CMakeFiles/allegro_acodec.dir/flags.make
addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o: addons/acodec/acodec.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/damien/workspace/battlechess/lib/allegro/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_ACODEC_SRC   -DALLEGRO_LIB_BUILD -o CMakeFiles/allegro_acodec.dir/acodec.c.o   -c /home/damien/workspace/battlechess/lib/allegro/addons/acodec/acodec.c

addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_acodec.dir/acodec.c.i"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_ACODEC_SRC   -DALLEGRO_LIB_BUILD -E /home/damien/workspace/battlechess/lib/allegro/addons/acodec/acodec.c > CMakeFiles/allegro_acodec.dir/acodec.c.i

addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_acodec.dir/acodec.c.s"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_ACODEC_SRC   -DALLEGRO_LIB_BUILD -S /home/damien/workspace/battlechess/lib/allegro/addons/acodec/acodec.c -o CMakeFiles/allegro_acodec.dir/acodec.c.s

addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o.requires:
.PHONY : addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o.requires

addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o.provides: addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o.requires
	$(MAKE) -f addons/acodec/CMakeFiles/allegro_acodec.dir/build.make addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o.provides.build
.PHONY : addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o.provides

addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o.provides.build: addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o

addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o: addons/acodec/CMakeFiles/allegro_acodec.dir/flags.make
addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o: addons/acodec/wav.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/damien/workspace/battlechess/lib/allegro/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_ACODEC_SRC   -DALLEGRO_LIB_BUILD -o CMakeFiles/allegro_acodec.dir/wav.c.o   -c /home/damien/workspace/battlechess/lib/allegro/addons/acodec/wav.c

addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_acodec.dir/wav.c.i"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_ACODEC_SRC   -DALLEGRO_LIB_BUILD -E /home/damien/workspace/battlechess/lib/allegro/addons/acodec/wav.c > CMakeFiles/allegro_acodec.dir/wav.c.i

addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_acodec.dir/wav.c.s"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_ACODEC_SRC   -DALLEGRO_LIB_BUILD -S /home/damien/workspace/battlechess/lib/allegro/addons/acodec/wav.c -o CMakeFiles/allegro_acodec.dir/wav.c.s

addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o.requires:
.PHONY : addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o.requires

addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o.provides: addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o.requires
	$(MAKE) -f addons/acodec/CMakeFiles/allegro_acodec.dir/build.make addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o.provides.build
.PHONY : addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o.provides

addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o.provides.build: addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o

addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o: addons/acodec/CMakeFiles/allegro_acodec.dir/flags.make
addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o: addons/acodec/flac.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/damien/workspace/battlechess/lib/allegro/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_ACODEC_SRC   -DALLEGRO_LIB_BUILD -o CMakeFiles/allegro_acodec.dir/flac.c.o   -c /home/damien/workspace/battlechess/lib/allegro/addons/acodec/flac.c

addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_acodec.dir/flac.c.i"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_ACODEC_SRC   -DALLEGRO_LIB_BUILD -E /home/damien/workspace/battlechess/lib/allegro/addons/acodec/flac.c > CMakeFiles/allegro_acodec.dir/flac.c.i

addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_acodec.dir/flac.c.s"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_ACODEC_SRC   -DALLEGRO_LIB_BUILD -S /home/damien/workspace/battlechess/lib/allegro/addons/acodec/flac.c -o CMakeFiles/allegro_acodec.dir/flac.c.s

addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o.requires:
.PHONY : addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o.requires

addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o.provides: addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o.requires
	$(MAKE) -f addons/acodec/CMakeFiles/allegro_acodec.dir/build.make addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o.provides.build
.PHONY : addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o.provides

addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o.provides.build: addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o

addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o: addons/acodec/CMakeFiles/allegro_acodec.dir/flags.make
addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o: addons/acodec/ogg.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/damien/workspace/battlechess/lib/allegro/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_ACODEC_SRC   -DALLEGRO_LIB_BUILD -o CMakeFiles/allegro_acodec.dir/ogg.c.o   -c /home/damien/workspace/battlechess/lib/allegro/addons/acodec/ogg.c

addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_acodec.dir/ogg.c.i"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_ACODEC_SRC   -DALLEGRO_LIB_BUILD -E /home/damien/workspace/battlechess/lib/allegro/addons/acodec/ogg.c > CMakeFiles/allegro_acodec.dir/ogg.c.i

addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_acodec.dir/ogg.c.s"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -DALLEGRO_ACODEC_SRC   -DALLEGRO_LIB_BUILD -S /home/damien/workspace/battlechess/lib/allegro/addons/acodec/ogg.c -o CMakeFiles/allegro_acodec.dir/ogg.c.s

addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o.requires:
.PHONY : addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o.requires

addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o.provides: addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o.requires
	$(MAKE) -f addons/acodec/CMakeFiles/allegro_acodec.dir/build.make addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o.provides.build
.PHONY : addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o.provides

addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o.provides.build: addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o

# Object files for target allegro_acodec
allegro_acodec_OBJECTS = \
"CMakeFiles/allegro_acodec.dir/acodec.c.o" \
"CMakeFiles/allegro_acodec.dir/wav.c.o" \
"CMakeFiles/allegro_acodec.dir/flac.c.o" \
"CMakeFiles/allegro_acodec.dir/ogg.c.o"

# External object files for target allegro_acodec
allegro_acodec_EXTERNAL_OBJECTS =

lib/liballegro_acodec.so.5.0.7: addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o
lib/liballegro_acodec.so.5.0.7: addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o
lib/liballegro_acodec.so.5.0.7: addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o
lib/liballegro_acodec.so.5.0.7: addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o
lib/liballegro_acodec.so.5.0.7: lib/liballegro_audio.so.5.0.7
lib/liballegro_acodec.so.5.0.7: /usr/lib/libFLAC.so
lib/liballegro_acodec.so.5.0.7: /usr/lib/libogg.so
lib/liballegro_acodec.so.5.0.7: /usr/lib/libvorbisfile.so
lib/liballegro_acodec.so.5.0.7: /usr/lib/libvorbis.so
lib/liballegro_acodec.so.5.0.7: /usr/lib/libogg.so
lib/liballegro_acodec.so.5.0.7: lib/liballegro.so.5.0.7
lib/liballegro_acodec.so.5.0.7: /usr/lib/libSM.so
lib/liballegro_acodec.so.5.0.7: /usr/lib/libICE.so
lib/liballegro_acodec.so.5.0.7: /usr/lib/libX11.so
lib/liballegro_acodec.so.5.0.7: /usr/lib/libXext.so
lib/liballegro_acodec.so.5.0.7: /usr/lib/libGL.so
lib/liballegro_acodec.so.5.0.7: /usr/lib/libGLU.so
lib/liballegro_acodec.so.5.0.7: /usr/lib/libopenal.so
lib/liballegro_acodec.so.5.0.7: /usr/lib/libvorbisfile.so
lib/liballegro_acodec.so.5.0.7: /usr/lib/libvorbis.so
lib/liballegro_acodec.so.5.0.7: addons/acodec/CMakeFiles/allegro_acodec.dir/build.make
lib/liballegro_acodec.so.5.0.7: addons/acodec/CMakeFiles/allegro_acodec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library ../../lib/liballegro_acodec.so"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/allegro_acodec.dir/link.txt --verbose=$(VERBOSE)
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/liballegro_acodec.so.5.0.7 ../../lib/liballegro_acodec.so.5.0 ../../lib/liballegro_acodec.so

lib/liballegro_acodec.so.5.0: lib/liballegro_acodec.so.5.0.7

lib/liballegro_acodec.so: lib/liballegro_acodec.so.5.0.7

# Rule to build all files generated by this target.
addons/acodec/CMakeFiles/allegro_acodec.dir/build: lib/liballegro_acodec.so
.PHONY : addons/acodec/CMakeFiles/allegro_acodec.dir/build

# Object files for target allegro_acodec
allegro_acodec_OBJECTS = \
"CMakeFiles/allegro_acodec.dir/acodec.c.o" \
"CMakeFiles/allegro_acodec.dir/wav.c.o" \
"CMakeFiles/allegro_acodec.dir/flac.c.o" \
"CMakeFiles/allegro_acodec.dir/ogg.c.o"

# External object files for target allegro_acodec
allegro_acodec_EXTERNAL_OBJECTS =

addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: lib/liballegro_audio.so.5.0.7
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libFLAC.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libogg.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libvorbisfile.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libvorbis.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libogg.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: lib/liballegro.so.5.0.7
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libSM.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libICE.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libX11.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libXext.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libGL.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libGLU.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libopenal.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libvorbisfile.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: /usr/lib/libvorbis.so
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: addons/acodec/CMakeFiles/allegro_acodec.dir/build.make
addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7: addons/acodec/CMakeFiles/allegro_acodec.dir/relink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library CMakeFiles/CMakeRelink.dir/liballegro_acodec.so"
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/allegro_acodec.dir/relink.txt --verbose=$(VERBOSE)
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && $(CMAKE_COMMAND) -E cmake_symlink_library CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7 CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0 CMakeFiles/CMakeRelink.dir/liballegro_acodec.so

addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0: addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7

addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so: addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so.5.0.7

# Rule to relink during preinstall.
addons/acodec/CMakeFiles/allegro_acodec.dir/preinstall: addons/acodec/CMakeFiles/CMakeRelink.dir/liballegro_acodec.so
.PHONY : addons/acodec/CMakeFiles/allegro_acodec.dir/preinstall

addons/acodec/CMakeFiles/allegro_acodec.dir/requires: addons/acodec/CMakeFiles/allegro_acodec.dir/acodec.c.o.requires
addons/acodec/CMakeFiles/allegro_acodec.dir/requires: addons/acodec/CMakeFiles/allegro_acodec.dir/wav.c.o.requires
addons/acodec/CMakeFiles/allegro_acodec.dir/requires: addons/acodec/CMakeFiles/allegro_acodec.dir/flac.c.o.requires
addons/acodec/CMakeFiles/allegro_acodec.dir/requires: addons/acodec/CMakeFiles/allegro_acodec.dir/ogg.c.o.requires
.PHONY : addons/acodec/CMakeFiles/allegro_acodec.dir/requires

addons/acodec/CMakeFiles/allegro_acodec.dir/clean:
	cd /home/damien/workspace/battlechess/lib/allegro/addons/acodec && $(CMAKE_COMMAND) -P CMakeFiles/allegro_acodec.dir/cmake_clean.cmake
.PHONY : addons/acodec/CMakeFiles/allegro_acodec.dir/clean

addons/acodec/CMakeFiles/allegro_acodec.dir/depend:
	cd /home/damien/workspace/battlechess/lib/allegro && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/damien/workspace/battlechess/lib/allegro /home/damien/workspace/battlechess/lib/allegro/addons/acodec /home/damien/workspace/battlechess/lib/allegro /home/damien/workspace/battlechess/lib/allegro/addons/acodec /home/damien/workspace/battlechess/lib/allegro/addons/acodec/CMakeFiles/allegro_acodec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : addons/acodec/CMakeFiles/allegro_acodec.dir/depend

