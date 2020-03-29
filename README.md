# OpenGL Playground
This is a playground repo, to play around while learning OpenGL.
Dependencies (includes and libraries) are included to avoid dealing with
dependency management and cross-platform building, for now...

## Building
The build process is set to use the `cl.exe` compiler (msvc++, Windows only)
and the build can be run with either `Make` or `nmake`.

`make` or `make build` will build the executable and copy the `data` folder contents into the `./build` location
`make clean` will delete the `./build` directory