# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "F:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "A:\Unipi\FDP EX\lab12File"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "A:\Unipi\FDP EX\lab12File\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\lab12File.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\lab12File.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\lab12File.dir\flags.make

CMakeFiles\lab12File.dir\main.cpp.obj: CMakeFiles\lab12File.dir\flags.make
CMakeFiles\lab12File.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="A:\Unipi\FDP EX\lab12File\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab12File.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\lab12File.dir\main.cpp.obj /FdCMakeFiles\lab12File.dir\ /FS -c "A:\Unipi\FDP EX\lab12File\main.cpp"
<<

CMakeFiles\lab12File.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab12File.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\lab12File.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "A:\Unipi\FDP EX\lab12File\main.cpp"
<<

CMakeFiles\lab12File.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab12File.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\lab12File.dir\main.cpp.s /c "A:\Unipi\FDP EX\lab12File\main.cpp"
<<

# Object files for target lab12File
lab12File_OBJECTS = \
"CMakeFiles\lab12File.dir\main.cpp.obj"

# External object files for target lab12File
lab12File_EXTERNAL_OBJECTS =

lab12File.exe: CMakeFiles\lab12File.dir\main.cpp.obj
lab12File.exe: CMakeFiles\lab12File.dir\build.make
lab12File.exe: CMakeFiles\lab12File.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="A:\Unipi\FDP EX\lab12File\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab12File.exe"
	"F:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\lab12File.dir --rc="F:\Windows Kits\10\bin\10.0.19041.0\x86\rc.exe" --mt="F:\Windows Kits\10\bin\10.0.19041.0\x86\mt.exe" --manifests -- C:\PROGRA~2\MICROS~4\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\lab12File.dir\objects1.rsp @<<
 /out:lab12File.exe /implib:lab12File.lib /pdb:"A:\Unipi\FDP EX\lab12File\cmake-build-debug\lab12File.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\lab12File.dir\build: lab12File.exe
.PHONY : CMakeFiles\lab12File.dir\build

CMakeFiles\lab12File.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab12File.dir\cmake_clean.cmake
.PHONY : CMakeFiles\lab12File.dir\clean

CMakeFiles\lab12File.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "A:\Unipi\FDP EX\lab12File" "A:\Unipi\FDP EX\lab12File" "A:\Unipi\FDP EX\lab12File\cmake-build-debug" "A:\Unipi\FDP EX\lab12File\cmake-build-debug" "A:\Unipi\FDP EX\lab12File\cmake-build-debug\CMakeFiles\lab12File.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\lab12File.dir\depend

