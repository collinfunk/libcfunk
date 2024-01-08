
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)

# Generate <monetary.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_MONETARY_H "1" CACHE STRING "")

check_include_file("monetary.h" HAVE_MONETARY_H)

if (HAVE_MONETARY_H)
  find_file(MONETARY_H_PATH NAMES "monetary.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "monetary.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-monetary-h.cmake)
endif ()

