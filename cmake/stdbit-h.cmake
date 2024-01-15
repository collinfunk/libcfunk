
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

# Generate <stdbit.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDBIT_H "1" CACHE STRING "")

check_include_file("stdbit.h" HAVE_STDBIT_H)

if (HAVE_STDBIT_H)
  find_file(STDBIT_H_PATH NAMES "stdbit.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "stdbit.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdbit-h.cmake)
endif ()

