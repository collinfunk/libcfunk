
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("mkstemps" "stdlib.h" HAVE_MKSTEMPS)
endif ()

# TODO
if (NOT HAVE_MKSTEMPS)
  message(FATAL_ERROR "No implementation of 'mkstemps' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-mkstemps.cmake)
endif ()

