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

For an optimized release build:

```
> cmake -DCMAKE_BUILD_TYPE=MINSIZEREL --build .
```

## Run:

On Linux and macOS:
```
> ./demo
```

On Windows:
```
> demo.exe
```

## Notes:

The repository contains a snapshots of the following libraries:

- Dear ImGui 
- cimgui (C bindings for Dear ImGui)
- sokol_gfx.h + sokol_app.h + sokol_imgui.h + sokol_time.h

I'm not planning to do regular updates to newer versions of those 
files, so the versions contained in here may be behind. Updating
your own copies is trivial though, just copy the new files from
the original repositories over the files contained here.

I tried to keep the CMake file as simple as possible (unfortunately
it's not quite as simple as I had liked, because of some cross-platform
differences).

All the important code is in ```src/demo.c```.

Enjoy!
