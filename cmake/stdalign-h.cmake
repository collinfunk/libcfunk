
include_guard(GLOBAL)

# Generate <stdalign.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDALIGN_H "1" CACHE STRING "")

check_include_file("stdalign.h" HAVE_STDALIGN_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdalign-h.cmake)
endif ()

