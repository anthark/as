include_directories(..)
add_library(BenchmarkLuaAs SHARED
    runner.h
    benchmark_runner_luaas.h
    benchmark_runner_luaas.cpp
)

target_link_libraries(BenchmarkLuaAs
    LuaIntegration
)
