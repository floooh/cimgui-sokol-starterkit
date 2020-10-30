# cimgui-sokol-starterkit

A minimal cross-platform starter-kit to write simple
Dear ImGui tools for Windows, Linux and macOS in C.

## Clone:

```bash
> git clone https://github.com/floooh/cimgui-sokol-starterkit
> cd cimgui-sokol-starterkit
```

## Build:

```bash
> mkdir build
> cd build

> cmake ..
> cmake --build .
```

To build a Release version on Linux and Mac:

```
> cmake -DCMAKE_BUILD_TYPE=MinSizeRel ..
> cmake --build .
```

To build a Release version on Windows with the VisualStudio toolchain:

```
> cmake ..
> cmake --build . --config MinSizeRel
```

NOTE: on Linux you'll also need to install the 'usual' dev-packages needed for X11+GL development.

## Run:

On Linux and macOS:
```
> ./demo
```

On Windows with the Visual Studio toolchain the exe is in a subdirectory:
```
> Debug\demo.exe
> MinSizeRel\demo.exe
```

## Notes:

The repository contains snapshots of the following libraries:

- [Dear ImGui](https://github.com/ocornut/imgui)
- [cimgui](https://github.com/cimgui/cimgui) (C bindings for Dear ImGui)
- [Sokol Headers](https://github.com/floooh/sokol) (only what's needed)

I'm not planning to do frequent updates to newer versions of those 
files, so the versions contained in here may be behind. Updating
your own copies is trivial though, just copy the new files from
the original repositories over the files contained here.

I tried to keep the CMake file as simple as possible (unfortunately
it's not quite as simple as I had liked, because of some cross-platform
differences).

All the important code is in ```demo.c```.

Enjoy!
