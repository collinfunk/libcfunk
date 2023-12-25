
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("getsubopt" "stdlib.h" HAVE_GETSUBOPT)
endif ()

# TODO
if (NOT HAVE_GETSUBOPT)
  message(FATAL_ERROR "No implementation of 'getsubopt' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

