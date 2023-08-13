
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(libcfunk LANGUAGES C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# All includes depend on these variables.
# Work in progress build system allowing only the functions a
# program needs. This CMakeLists.txt file is used for testing.

if (NOT DEFINED LIBCFUNK_LIBRARY_NAME)
  set(LIBCFUNK_LIBRARY_NAME cfunk)
endif ()

if (NOT DEFINED LIBCFUNK_SOURCE_DIR)
  set(LIBCFUNK_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/lib)
endif ()

if (NOT DEFINED LIBCFUNK_BUILD_DIR)
  set(LIBCFUNK_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/lib)
endif ()

if (NOT DEFINED LIBCFUNK_MODULE_DIR)
  set(LIBCFUNK_MODULE_DIR ${CMAKE_CURRENT_LIST_DIR}/cmake)
endif ()

include(cmake/libcfunk-init.cmake)

include(cmake/stdio.cmake)
include(cmake/stdlib.cmake)
include(cmake/string.cmake)
include(cmake/strings.cmake)
include(cmake/stdint.cmake)
include(cmake/inttypes.cmake)
include(cmake/sys-random.cmake)

include(cmake/getrandom.cmake)
include(cmake/getentropy.cmake)

include(cmake/ffs.cmake)
include(cmake/fls.cmake)
include(cmake/popcount.cmake)

include(cmake/reallocarray.cmake)

include(cmake/read-nointr.cmake)
include(cmake/write-nointr.cmake)
include(cmake/read-full.cmake)
include(cmake/write-full.cmake)

include(cmake/libcfunk-final.cmake)

add_subdirectory(lib)
add_subdirectory(tests)
