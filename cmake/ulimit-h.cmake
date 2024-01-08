
include_guard(GLOBAL)

# Generate <ulimit.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ULIMIT_H "1" CACHE STRING "")

check_include_file("ulimit.h" HAVE_ULIMIT_H)

if (HAVE_ULIMIT_H)
  find_file(ULIMIT_H_PATH NAMES "ulimit.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ulimit-h.cmake)
endif ()

