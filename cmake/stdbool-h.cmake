
include_guard(GLOBAL)

# Generate <stdbool.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDBOOL_H "1" CACHE STRING "")

check_include_file("stdbool.h" HAVE_STDBOOL_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdbool-h.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdbool-c23.cmake)
endif ()

