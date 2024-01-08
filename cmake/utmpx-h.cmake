
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-time-h.cmake)

# Generate <utmpx.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_UTMPX_H "1" CACHE STRING "")

check_include_file("utmpx.h" HAVE_UTMPX_H)

if (HAVE_UTMPX_H)
  find_file(UTMPX_H_PATH NAMES "utmpx.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "utmpx.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct utmpx" STRUCT_UTMPX)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utmpx-h.cmake)
endif ()

