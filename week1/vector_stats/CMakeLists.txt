cmake_minimum_required(VERSION 3.10)
project(vector_stats)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

# Main app
add_executable(vector_stats
    src/main.cpp
    src/compute_stats.cpp
)

# Test app
add_executable(run_tests
    src/test_stats.cpp
    src/compute_stats.cpp
)