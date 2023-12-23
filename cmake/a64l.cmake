
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("a64l" "stdlib.h" HAVE_A64L)
endif ()

set(LIBCFUNK_DECLARE_A64L "1" CACHE STRING "")

if (NOT HAVE_A64L OR LIBCFUNK_REPLACE_A64L)
  include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/a64l.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-a64l.cmake)
endif ()

