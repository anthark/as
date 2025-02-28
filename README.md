Agnostic Scripting Project
========

Getting Started
---------------

### Prerequisites
- `cmake`, `ninja`, any C++ compiler
- `LLVM 18.1.0`. For macOS and arm64, if it is not supplied, the pre-built binaries are downloaded automatically. For Windows prebuild package can be downloaded from here: https://github.com/llvm/llvm-project/releases/download/llvmorg-18.1.0/clang+llvm-18.1.0-x86_64-pc-windows-msvc.tar.xz
- `LuaJIT` downloaded and built if you want to use Lua benchmarks

The environment variable `LLVM_ROOT_DIR` should be set to the directory where the LLVM 18.1.0 binaries are located 
(this directory should contain `bin`, `include`, `lib`, and other directories). 
In case the variable is not set, the binaries are downloaded during the `cmake` run.
However, currently, downloading is only supported for macOS, arm64.

```shell
git clone git@github.com:NauEngine/as_proto.git
cd as_proto
```

#### Build from command line
```shell
cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja -S . -B ./build
cmake --build ./build --target AScriptTest -j 8
./build/test/AScriptTest
```

#### Build from command line with Visual Studio 2022
```shell
cmake -S . -B ./build -G "Visual Studio 17"
cmake --build ./build
```
Or (if you want to use LuaJIT): 
```shell
cmake -S . -B ./build -G "Visual Studio 17" -DLUA_JIT_LIBS=<path-to-luajit-libs> -DLUA_JIT_INCLUDE=<path-to-luajit-includes>
cmake --build ./build
```
##### Known issue: 
 If linker complains about diaguids.lib path (it tries to look for it at Professional package of Visual Studio 2019), just create this folder and copy DIA SDK to it. 
##### Known issue: 
You can only build Release, MinSizeRel and RelWithDebInfo if you use downloaded LLVM. It is needed to compile LLVM locally in Debug configuration to compile AS in Debug configuration. 

#### Build with CLion
Simply open the project with CLion and set `LLVM_ROOT_DIR` environment variable.


### Debugging

Debug Info support is enabled in the JIT, and according to information on the internet, 
GDB and LLDB debuggers support Debug Info in JITed code.

In macOS and LLDB JITed code debugging is disabled by default, and it has to be enabled manually. You can enable it 
by adding a file `~/.lldbinit` with the following content:
```
settings set plugin.jit-loader.gdb.enable on
```
As a result, the debugging will be functioning both in CLion (in macOS CLion uses embedded LLDB by default) and in LLDB.

Reference
------------
- [Coding Style Guide](./docs/coding_style_guide.md)
- [Architecture](./docs/architecture.md)
- [How To: Testing](./docs/howto_test.md)
- [How To: Introducing A New Language](./docs/howto_new_language.md)
- [What's Next](./docs/whats_next.md)


