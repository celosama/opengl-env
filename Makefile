# GLOBAL config
INCLUDES_DIRECTORY = common\includes
LIBRARIES_DIRECTORY = common\libraries
DEPENDENCIES = gdi32.lib kernel32.lib user32.lib shell32.lib opengl32.lib glfw3.lib glew32s.lib

# DEBUG config
DEBUG_EXE_DIRECTORY = build\debug\executable
DEBUG_OBJ_DIRECTORY = build\debug\objects
DEBUG_COMPILER_OPTIONS = /EHsc /MDd /Za /Od

# RELEASE config
RELEASE_EXE_DIRECTORY = build\release\executable
RELEASE_OBJ_DIRECTORY = build\release\objects
RELEASE_COMPILER_OPTIONS = /EHsc /MD /Za /O2 /GL

debug:
	if not exist $(DEBUG_EXE_DIRECTORY) mkdir $(DEBUG_EXE_DIRECTORY)
	if not exist $(DEBUG_OBJ_DIRECTORY) mkdir $(DEBUG_OBJ_DIRECTORY)
	cl $(DEBUG_COMPILER_OPTIONS) /I $(INCLUDES_DIRECTORY) /Fe:$(DEBUG_EXE_DIRECTORY)\main.exe /Fo:$(DEBUG_OBJ_DIRECTORY)\ src\*.cpp /link /LIBPATH:$(LIBRARIES_DIRECTORY) $(DEPENDENCIES)

release:
	if not exist $(RELEASE_EXE_DIRECTORY) mkdir $(RELEASE_EXE_DIRECTORY)
	if not exist $(RELEASE_OBJ_DIRECTORY) mkdir $(RELEASE_OBJ_DIRECTORY)
	cl $(RELEASE_COMPILER_OPTIONS) /I $(INCLUDES_DIRECTORY) /Fe:$(RELEASE_EXE_DIRECTORY)\main.exe /Fo:$(RELEASE_OBJ_DIRECTORY)\ src\*.cpp /link /RELEASE /LIBPATH:$(LIBRARIES_DIRECTORY) $(DEPENDENCIES)

clean:
	rmdir /q /s build

# Custom tasks
# ------------------------------------------------------

# Run debug executable
rund:
	start $(DEBUG_EXE_DIRECTORY)\main.exe

# Run release executable
run:
	start $(RELEASE_EXE_DIRECTORY)\main.exe