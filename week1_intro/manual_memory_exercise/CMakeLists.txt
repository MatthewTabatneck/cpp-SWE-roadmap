cmake_minimum_required(VERSION 3.10)
project(manual_memory_exercise)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Main app
add_executable(manual_memory_exercise
    main.cpp
)
