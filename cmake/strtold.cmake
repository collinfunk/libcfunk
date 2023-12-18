
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtold" "stdlib.h" HAVE_STRTOLD)
endif ()

# TODO
if (NOT HAVE_STRTOLD)
  message(FATAL_ERROR "No implementation of 'strtold' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strtold.cmake)
endif ()

