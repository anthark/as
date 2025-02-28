add_library(BenchmarkLuaJit SHARED
    benchmark_runner_luajit.h
    benchmark_runner_luajit.cpp
)

set(LUA_JIT_INCLUDE "" CACHE STRING "Path to luajit includes")
set(LUA_JIT_LIBS "" CACHE STRING "Path to luajit libs")

target_include_directories(BenchmarkLuaJit PRIVATE "${LUA_JIT_INCLUDE}")
target_link_directories(BenchmarkLuaJit PRIVATE "${LUA_JIT_LIBS}")

if (MSVC)
target_link_libraries(BenchmarkLuaJit "${LUA_JIT_LIBS}/luajit.lib")
target_link_libraries(BenchmarkLuaJit "${LUA_JIT_LIBS}/lua51.lib")
else()
target_link_libraries(BenchmarkLuaJit "${LUA_JIT_LIBS}/libluajit-5.1.a")
endif()

if(MSVC)
add_custom_command(TARGET BenchmarkLuaJit POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ../../$<CONFIG>
    COMMAND ${CMAKE_COMMAND} -E copy $<CONFIG>/BenchmarkLuaJit.dll ../../$<CONFIG>/
    COMMAND ${CMAKE_COMMAND} -E copy ${LUA_JIT_LIBS}/lua51.dll ../../$<CONFIG>/
)
endif()