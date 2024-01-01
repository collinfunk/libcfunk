
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("realpath" "stdlib.h" HAVE_REALPATH)
endif ()

if (NOT HAVE_REALPATH)
  message(FATAL_ERROR "No implementation of 'realpath' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

