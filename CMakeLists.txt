
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

if (NOT DEFINED LIBCFUNK_TEST_SOURCE_DIR)
  set(LIBCFUNK_TEST_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/tests)
endif ()

if (NOT DEFINED LIBCFUNK_TEST_BUILD_DIR)
  set(LIBCFUNK_TEST_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/tests)
endif ()

if (NOT DEFINED LIBCFUNK_BUILD_DIR)
  set(LIBCFUNK_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/lib)
endif ()

if (NOT DEFINED LIBCFUNK_MODULE_DIR)
  set(LIBCFUNK_MODULE_DIR ${CMAKE_CURRENT_LIST_DIR}/cmake)
endif ()

# Always comes first
include(cmake/libcfunk-init.cmake)

# All modules include here for testing.

include(cmake/inttypes.cmake)
include(cmake/stdint.cmake)
include(cmake/string.cmake)
include(cmake/strings.cmake)
include(cmake/stdio.cmake)
include(cmake/stdlib.cmake)
include(cmake/sys-random.cmake)

# <string.h>
include(cmake/explicit-bzero.cmake)
include(cmake/stpcpy.cmake)
include(cmake/strchrnul.cmake)
include(cmake/strdup.cmake)
include(cmake/strmode.cmake)
include(cmake/strndup.cmake)

# <strings.h>
include(cmake/ffs.cmake)
include(cmake/fls.cmake)
include(cmake/popcount.cmake)

# <stdio.h>
include(cmake/getdelim.cmake)
include(cmake/getline.cmake)
include(cmake/unlocked-stdio.cmake)

# <stdlib.h>
include(cmake/reallocarray.cmake)

# <sys/random.h> (and <unistd.h> if getentropy(2) is a system call)
include(cmake/getentropy.cmake)
include(cmake/getrandom.cmake)

# Hash functions
include(cmake/md4.cmake)
include(cmake/md5.cmake)
include(cmake/sha256.cmake)
include(cmake/sha512.cmake)

# Misc
include(cmake/bstree.cmake)
include(cmake/bswap.cmake)
include(cmake/circular-shift.cmake)
include(cmake/crc32.cmake)
include(cmake/hash-map.cmake)
include(cmake/list.cmake)
include(cmake/rbtree.cmake)
include(cmake/read-full.cmake)
include(cmake/read-nointr.cmake)
include(cmake/slist.cmake)
include(cmake/splay-tree.cmake)
include(cmake/write-full.cmake)
include(cmake/write-nointr.cmake)
include(cmake/xmalloc.cmake)

# Always last
include(cmake/libcfunk-final.cmake)

