include_directories(..)
add_library(BenchmarkLuaClassic SHARED
    benchmark_runner_luaclassic.h
    benchmark_runner_luaclassic.cpp
)

#target_compile_options(BenchmarkLuaClassic PRIVATE -fvisibility=hidden)
#target_link_options(BenchmarkLuaClassic PRIVATE -Wl,--exclude-libs,ALL)