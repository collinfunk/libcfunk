
include_guard(GLOBAL)

# Generate <fnmatch.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_FNMATCH_H "1" CACHE STRING "")

check_include_file("fnmatch.h" HAVE_FNMATCH_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fnmatch-h.cmake)
endif ()
