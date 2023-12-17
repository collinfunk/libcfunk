
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtod" "stdlib.h" HAVE_STRTOD)
endif ()

# TODO
if (NOT HAVE_STRTOD)
  message(FATAL_ERROR "No implementation of 'strtod' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

