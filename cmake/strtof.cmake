
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtof" "stdlib.h" HAVE_STRTOF)
endif ()

# TODO
if (NOT HAVE_STRTOF)
  message(FATAL_ERROR "No implementation of 'strtof' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

