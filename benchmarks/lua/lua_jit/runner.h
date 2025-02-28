//
// Created by Alex Zelenshikov on 22.05.2024.
//

#pragma once

#include <memory>

#include "../../benchmark_runner.h"

namespace as::benchmark
{
    BENCHMARK_EXPORT std::unique_ptr<IBenchmarkRunner> getRunnerLuaJit();
}
