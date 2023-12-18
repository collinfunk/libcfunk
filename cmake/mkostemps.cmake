
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("mkostemps" "stdlib.h" HAVE_MKOSTEMPS)
endif ()

# TODO
if (NOT HAVE_MKOSTEMPS)
  message(FATAL_ERROR "No implementation of 'mkostemps' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-mkostemps.cmake)
endif ()

