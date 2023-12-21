
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <glob.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_GLOB_H "1" CACHE STRING "")

check_include_file("glob.h" HAVE_GLOB_H)

if (HAVE_GLOB_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "glob.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("glob_t" GLOB_T)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-glob-h.cmake)
endif ()

