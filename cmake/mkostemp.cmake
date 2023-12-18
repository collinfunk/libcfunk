
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("mkostemp" "stdlib.h" HAVE_MKOSTEMP)
endif ()

# TODO
if (NOT HAVE_MKOSTEMP)
  message(FATAL_ERROR "No implementation of 'mkostemp' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-mkostemp.cmake)
endif ()

