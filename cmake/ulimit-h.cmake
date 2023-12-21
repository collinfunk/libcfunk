
include_guard(GLOBAL)

# Generate <ulimit.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ULIMIT_H "1" CACHE STRING "")

check_include_file("ulimit.h" HAVE_ULIMIT_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ulimit-h.cmake)
endif ()

