# cimgui-sokol-starterkit

A minimal cross-platform starter-kit to write simple
Dear ImGui tools for Windows, Linux and macOS in C.

[WASM version](https://floooh.github.io/cimgui-sokol-starterkit/) (see below for build instructions)

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

```bash
> cmake -DCMAKE_BUILD_TYPE=MinSizeRel ..
> cmake --build .
```

To build a Release version on Windows with the VisualStudio toolchain:

```bash
> cmake ..
> cmake --build . --config MinSizeRel
```

To build in w64devkit console
```
> cmake -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=make ..
> cmake --build .
```
NOTE: on Linux you'll also need to install the 'usual' dev-packages needed for X11+GL development.

## Run:

On Linux and macOS:
```bash
> ./demo
```

On Windows with the Visual Studio toolchain the exe is in a subdirectory:
```bash
> Debug\demo.exe
> MinSizeRel\demo.exe
```

## Build and Run WASM/HTML version via Emscripten (Linux, macOS)

Setup the emscripten SDK as described here:

https://emscripten.org/docs/getting_started/downloads.html#installation-instructions

Don't forget to run ```source ./emsdk_env.sh``` after activating the SDK.

And then in the ```cimgui-sokol-starterkit``` directory:

```
mkdir build
cd build
emcmake cmake -DCMAKE_BUILD_TYPE=MinSizeRel ..
cmake --build .
```

To run the compilation result in the system web browser:

```
> emrun demo.html
```

...which should look like [this](https://floooh.github.io/cimgui-sokol-starterkit/).

## IDE Support

### Visual Studio (Windows)

On Windows, cmake will automatically create a Visual Studio solution file in
the build directory, which can be opened (inside the build directory) with:

```bash
> cmake --open .
```

### Xcode (macOS)

Replace ```cmake ..``` with ```cmake -GXcode ..``` and open the generated
Xcode project:

```bash
> cmake -GXcode ..
> cmake --open .
```

### Visual Studio Code (Windows, Linux, macOS)

Use the [MS C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
together with the [MS CMake Tools extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
and start Visual Studio code from the project's root directory. The CMake
extension will detect the CMakeLists.txt file and take over from there.

## Notes:

The repository contains snapshots of the following libraries:

- [Dear ImGui](https://github.com/ocornut/imgui)
- [Sokol Headers](https://github.com/floooh/sokol) (only what's needed)

C bindings were generated via [dear_bindings](https://github.com/dearimgui/dear_bindings)
and are located in [floooh/dcimgui](https://github.com/floooh/dcimgui)

I'm not planning to do frequent updates to newer versions of those
files, so the versions contained in here may be behind. Updating
your own copies is trivial though, just copy the new files from
the original repositories over the files contained here.

I tried to keep the CMake file as simple as possible (unfortunately
it's not quite as simple as I had liked, because of some cross-platform
differences).

All the important code is in ```demo.c```.

Enjoy!
