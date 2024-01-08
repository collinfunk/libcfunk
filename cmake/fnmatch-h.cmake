
include_guard(GLOBAL)

# Generate <fnmatch.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_FNMATCH_H "1" CACHE STRING "")

check_include_file("fnmatch.h" HAVE_FNMATCH_H)

if (HAVE_FNMATCH_H)
  find_file(FNMATCH_H_PATH NAMES "fnmatch.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fnmatch-h.cmake)
endif ()
