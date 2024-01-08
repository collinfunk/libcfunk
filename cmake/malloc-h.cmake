
include_guard(GLOBAL)

# Generate <malloc.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_MALLOC_H "1" CACHE STRING "")

check_include_file("malloc.h" HAVE_MALLOC_H)

if (HAVE_MALLOC_H)
  find_file(MALLOC_H_PATH NAMES "malloc.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-malloc-h.cmake)
endif ()

