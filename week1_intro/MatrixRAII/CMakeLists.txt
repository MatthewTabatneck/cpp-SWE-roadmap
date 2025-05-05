cmake_minimum_required(VERSION 3.10)
project(MatrixRAII)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable extra warnings
add_compile_options(-Wall -Wextra -pedantic)

# Add include directory for headers
include_directories(include)

# Automatically find all .cpp files inside src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# Define executable
add_executable(matrix_app ${SOURCES})
