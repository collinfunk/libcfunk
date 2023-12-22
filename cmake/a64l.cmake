
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("a64l" "stdlib.h" HAVE_A64L)
endif ()

# TODO
if (NOT HAVE_A64L)
  message(FATAL_ERROR "No implementation of 'a64l' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-a64l.cmake)
endif ()

