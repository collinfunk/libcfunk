
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("l64a" "stdlib.h" HAVE_L64A)
endif ()

# TODO
if (NOT HAVE_L64A)
  message(FATAL_ERROR "No implementation of 'l64a' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-l64a.cmake)
endif ()

