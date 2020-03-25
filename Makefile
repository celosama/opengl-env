DEBUG_EXE_DIRECTORY = build\debug\executable
DEBUG_OBJ_DIRECTORY = build\debug\objects
RELEASE_EXE_DIRECTORY = build\release\executable
RELEASE_OBJ_DIRECTORY = build\release\objects

debug:
				if not exist $(DEBUG_EXE_DIRECTORY) mkdir $(DEBUG_EXE_DIRECTORY)
				if not exist $(DEBUG_OBJ_DIRECTORY) mkdir $(DEBUG_OBJ_DIRECTORY)
				cl /EHsc /Za /Od /Fe:$(DEBUG_EXE_DIRECTORY)\ /Fo:$(DEBUG_OBJ_DIRECTORY)\ src\*.cpp

release:
				if not exist $(RELEASE_EXE_DIRECTORY) mkdir $(RELEASE_EXE_DIRECTORY)
				if not exist $(RELEASE_OBJ_DIRECTORY) mkdir $(RELEASE_OBJ_DIRECTORY)
				cl /EHsc /Za /O2 /GL /Fe:$(RELEASE_EXE_DIRECTORY)\ /Fo:$(RELEASE_OBJ_DIRECTORY)\ src\*.cpp

clean:
			rmdir /q /s build