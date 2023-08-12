
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(libcfunk LANGUAGES C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT LIBCFUNK_MODULE_DIR)
  set (LIBCFUNK_MODULE_DIR ${CMAKE_CURRENT_LIST_DIR}/cmake)
endif ()

include(cmake/libcfunk-init.cmake)

include(cmake/stdio.cmake)
include(cmake/stdlib.cmake)
include(cmake/string.cmake)
include(cmake/strings.cmake)
include(cmake/stdint.cmake)
include(cmake/inttypes.cmake)

add_subdirectory(lib)
add_subdirectory(tests)
