cmake_minimum_required(VERSION 3.10)
project(vector_stats)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Main program
add_executable(vector_stats main.cpp compute_stats.cpp)

# Test suite
add_executable(run_tests test_stats.cpp compute_stats.cpp)