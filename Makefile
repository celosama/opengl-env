debug:
				if not exist build\debug\executable mkdir build\debug\executable
				if not exist build\debug\objects mkdir build\debug\objects
				cl /EHsc /Za /Od /Fe:build\debug\executable\ /Fo:build\debug\objects\ main.cpp src\*.cpp

release:
				if not exist build\release\executable mkdir build\release\executable
				if not exist build\release\objects mkdir build\release\objects
				cl /EHsc /Za /O2 /GL /Fe:build\release\executable\ /Fo:build\release\objects\ main.cpp src\*.cpp