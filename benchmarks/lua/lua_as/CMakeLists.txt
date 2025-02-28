include_directories(..)
add_library(BenchmarkLuaAs SHARED
    runner.h
    benchmark_runner_luaas.h
    benchmark_runner_luaas.cpp
)

target_link_libraries(BenchmarkLuaAs
    LuaIntegration
)

if(MSVC)
add_custom_command(TARGET BenchmarkLuaAs POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ../../$<CONFIG>
    COMMAND ${CMAKE_COMMAND} -E copy $<CONFIG>/BenchmarkLuaAs.dll ../../$<CONFIG>/
)
endif()
