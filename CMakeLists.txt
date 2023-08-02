
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(libcfunk LANGUAGES C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(lib)
add_subdirectory(tests)
