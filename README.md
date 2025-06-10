## wasm-ld crash reproducer

First, review the `install_emsdk.sh` script.

The emsdk hash `65c4e7ad07766fdc9dc514159bd5ac4449393e17` is the first bad version,
and hash `8103ffedfb0c42d231c6af6859a5a1a832260b43` is the last good version.

In a bash or zsh shell:

```
git clone --branch wasm-ld-crash https://github.com/floooh/cimgui-sokol-starterkit
```
```
cd cimgui-sokol-starterkit
```
```
source install_emsdk.sh
```
```
mkdir build && cd build
```
```
emcmake cmake -DCMAKE_BUILD_TYPE=Release ..
```
```
cmake --build . -- VERBOSE=1
```

...when retrying the installation, don't forget to do this in a new shell.

The `wasm-ld` step should break with:

```
/opt/homebrew/bin/cmake -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=1
/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/emscripten/emcc -O3 -DNDEBUG -flto --shell-file ../sokol/shell.html -sUSE_WEBGL2=1 -sNO_FILESYSTEM=1 -sASSERTIONS=0 -sMALLOC=emmalloc --closure=1 @CMakeFiles/demo.dir/objects1.rsp -o demo.html @CMakeFiles/demo.dir/linkLibs.rsp
Assertion failed: (llvm::isUIntN(BitWidth, val) && "Value is not an N-bit unsigned value"), function APInt, file APInt.h, line 128.
PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace.
Stack dump:
0.      Program arguments: /Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/bin/wasm-ld -o demo.wasm CMakeFiles/demo.dir/demo.c.o libsokol.a libcimgui.a -L/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/lto -L/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/emscripten/src/lib -lGL-webgl2-getprocaddr -lal -lhtml5 -lstubs -lnoexit -lc -lemmalloc -lcompiler_rt -lc++-noexcept -lc++abi-noexcept -lsockets -mllvm -combiner-global-alias-analysis=false -mllvm -enable-emscripten-sjlj -mllvm -disable-lsr /var/folders/dz/g9ydwg8973z9nn5bvffcwf3h0000gn/T/tmpju1azu1elibemscripten_js_symbols.so --strip-debug -u__cxa_atexit --export=_emscripten_stack_alloc --export=__wasm_call_ctors --export=emscripten_stack_get_current --export=_emscripten_stack_restore --export-if-defined=__start_em_asm --export-if-defined=__stop_em_asm --export-if-defined=__start_em_lib_deps --export-if-defined=__stop_em_lib_deps --export-if-defined=__start_em_js --export-if-defined=__stop_em_js --export-if-defined=main --export-if-defined=__main_argc_argv --export-table -z stack-size=65536 --no-growable-memory --initial-heap=16777216 --no-entry --table-base=1 --global-base=1024
1.      Running pass 'Function Pass Manager' on module 'ld-temp.o'.
2.      Running pass 'WebAssembly Instruction Selection' on function '@_ZN5ImGui12ColorPicker4EPKcPfiPKf'
 #0 0x000000010972f3c0 llvm::sys::PrintStackTrace(llvm::raw_ostream&, int) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0x17f3c0)
 #1 0x000000010972d178 llvm::sys::RunSignalHandlers() (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0x17d178)
 #2 0x000000010972fa7c SignalHandler(int, __siginfo*, void*) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0x17fa7c)
 #3 0x000000018b810624 (/usr/lib/system/libsystem_platform.dylib+0x1804ac624)
 #4 0x000000018b7d688c (/usr/lib/system/libsystem_pthread.dylib+0x18047288c)
 #5 0x000000018b6dfc60 (/usr/lib/system/libsystem_c.dylib+0x18037bc60)
 #6 0x000000018b6deeec (/usr/lib/system/libsystem_c.dylib+0x18037aeec)
 #7 0x000000010a26ef74 llvm::SelectionDAG::getNOT(llvm::SDLoc const&, llvm::SDValue, llvm::EVT) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0xcbef74)
 #8 0x000000010a075670 (anonymous namespace)::DAGCombiner::visitSUB(llvm::SDNode*) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0xac5670)
 #9 0x000000010a072cf0 (anonymous namespace)::DAGCombiner::combine(llvm::SDNode*) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0xac2cf0)
#10 0x000000010a06fea4 llvm::SelectionDAG::Combine(llvm::CombineLevel, llvm::BatchAAResults*, llvm::CodeGenOptLevel) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0xabfea4)
#11 0x000000010a2d0774 llvm::SelectionDAGISel::CodeGenAndEmitDAG() (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0xd20774)
#12 0x000000010a2cfcac llvm::SelectionDAGISel::SelectAllBasicBlocks(llvm::Function const&) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0xd1fcac)
#13 0x000000010a2cce78 llvm::SelectionDAGISel::runOnMachineFunction(llvm::MachineFunction&) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0xd1ce78)
#14 0x000000010a2cb300 llvm::SelectionDAGISelLegacy::runOnMachineFunction(llvm::MachineFunction&) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0xd1b300)
#15 0x0000000109cbd4c4 llvm::MachineFunctionPass::runOnFunction(llvm::Function&) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0x70d4c4)
#16 0x00000001099204e0 llvm::FPPassManager::runOnFunction(llvm::Function&) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0x3704e0)
#17 0x0000000109928338 llvm::FPPassManager::runOnModule(llvm::Module&) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0x378338)
#18 0x0000000109920eb8 llvm::legacy::PassManagerImpl::run(llvm::Module&) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0x370eb8)
#19 0x000000010b61ffdc codegen(llvm::lto::Config const&, llvm::TargetMachine*, std::__2::function<llvm::Expected<std::__2::unique_ptr<llvm::CachedFileStream, std::__2::default_delete<llvm::CachedFileStream>>> (unsigned int, llvm::Twine const&)>, unsigned int, llvm::Module&, llvm::ModuleSummaryIndex const&) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0x206ffdc)
#20 0x000000010b61f274 llvm::lto::backend(llvm::lto::Config const&, std::__2::function<llvm::Expected<std::__2::unique_ptr<llvm::CachedFileStream, std::__2::default_delete<llvm::CachedFileStream>>> (unsigned int, llvm::Twine const&)>, unsigned int, llvm::Module&, llvm::ModuleSummaryIndex&) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0x206f274)
#21 0x000000010b6085fc llvm::lto::LTO::runRegularLTO(std::__2::function<llvm::Expected<std::__2::unique_ptr<llvm::CachedFileStream, std::__2::default_delete<llvm::CachedFileStream>>> (unsigned int, llvm::Twine const&)>) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0x20585fc)
#22 0x000000010b607b3c llvm::lto::LTO::run(std::__2::function<llvm::Expected<std::__2::unique_ptr<llvm::CachedFileStream, std::__2::default_delete<llvm::CachedFileStream>>> (unsigned int, llvm::Twine const&)>, llvm::FileCache) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/lib/libLLVM.dylib+0x2057b3c)
#23 0x0000000104489644 lld::wasm::BitcodeCompiler::compile() (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/bin/lld+0x1003cd644)
#24 0x000000010448bed8 lld::wasm::SymbolTable::compileBitcodeFiles() (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/bin/lld+0x1003cfed8)
#25 0x0000000104472000 lld::wasm::(anonymous namespace)::LinkerDriver::linkerMain(llvm::ArrayRef<char const*>) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/bin/lld+0x1003b6000)
#26 0x000000010446e10c lld::wasm::link(llvm::ArrayRef<char const*>, llvm::raw_ostream&, llvm::raw_ostream&, bool, bool) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/bin/lld+0x1003b210c)
#27 0x00000001040bee7c lld::unsafeLldMain(llvm::ArrayRef<char const*>, llvm::raw_ostream&, llvm::raw_ostream&, llvm::ArrayRef<lld::DriverDef>, bool) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/bin/lld+0x100002e7c)
#28 0x00000001040bda40 lld_main(int, char**, llvm::ToolContext const&) (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/bin/lld+0x100001a40)
#29 0x00000001040be0f4 main (/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/bin/lld+0x1000020f4)
#30 0x000000018b436b98
emcc: error: '/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/bin/wasm-ld -o demo.wasm CMakeFiles/demo.dir/demo.c.o libsokol.a libcimgui.a -L/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/lto -L/Users/floh/projects/cimgui-sokol-starterkit/emsdk/upstream/emscripten/src/lib -lGL-webgl2-getprocaddr -lal -lhtml5 -lstubs -lnoexit -lc -lemmalloc -lcompiler_rt -lc++-noexcept -lc++abi-noexcept -lsockets -mllvm -combiner-global-alias-analysis=false -mllvm -enable-emscripten-sjlj -mllvm -disable-lsr /var/folders/dz/g9ydwg8973z9nn5bvffcwf3h0000gn/T/tmpju1azu1elibemscripten_js_symbols.so --strip-debug -u__cxa_atexit --export=_emscripten_stack_alloc --export=__wasm_call_ctors --export=emscripten_stack_get_current --export=_emscripten_stack_restore --export-if-defined=__start_em_asm --export-if-defined=__stop_em_asm --export-if-defined=__start_em_lib_deps --export-if-defined=__stop_em_lib_deps --export-if-defined=__start_em_js --export-if-defined=__stop_em_js --export-if-defined=main --export-if-defined=__main_argc_argv --export-table -z stack-size=65536 --no-growable-memory --initial-heap=16777216 --no-entry --table-base=1 --global-base=1024' failed (received SIGABRT (-6))
```
