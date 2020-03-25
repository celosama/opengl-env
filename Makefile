# DEBUG config
DEBUG_EXE_DIRECTORY = build\debug\executable
DEBUG_OBJ_DIRECTORY = build\debug\objects
DEBUG_COMPILER_OPTIONS = /EHsc /Za /Od

# RELEASE config
RELEASE_EXE_DIRECTORY = build\release\executable
RELEASE_OBJ_DIRECTORY = build\release\objects
RELEASE_COMPILER_OPTIONS = /EHsc /Za /O2 /GL

debug:
	if not exist $(DEBUG_EXE_DIRECTORY) mkdir $(DEBUG_EXE_DIRECTORY)
	if not exist $(DEBUG_OBJ_DIRECTORY) mkdir $(DEBUG_OBJ_DIRECTORY)
	cl $(DEBUG_COMPILER_OPTIONS) /Fe:$(DEBUG_EXE_DIRECTORY)\ /Fo:$(DEBUG_OBJ_DIRECTORY)\ src\*.cpp

release:
	if not exist $(RELEASE_EXE_DIRECTORY) mkdir $(RELEASE_EXE_DIRECTORY)
	if not exist $(RELEASE_OBJ_DIRECTORY) mkdir $(RELEASE_OBJ_DIRECTORY)
	cl $(RELEASE_COMPILER_OPTIONS) /Fe:$(RELEASE_EXE_DIRECTORY)\ /Fo:$(RELEASE_OBJ_DIRECTORY)\ src\*.cpp

clean:
	rmdir /q /s build