
include_guard(GLOBAL)

# Generate <stdatomic.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDATOMIC_H "1" CACHE STRING "")

check_include_file("stdatomic.h" HAVE_STDATOMIC_H)

if (HAVE_STDATOMIC_H)
  find_file(STDATOMIC_H_PATH NAMES "stdatomic.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "stdatomic.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdatomic-h.cmake)
endif ()

