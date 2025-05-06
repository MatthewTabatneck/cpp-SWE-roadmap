cmake_minimum_required(VERSION 3.10)
project(MatrixRAII)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

# Main app
add_executable(MatrixRAII
    src/main.cpp
    src/Matrix.cpp
)