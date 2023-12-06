
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("llabs" "stdlib.h" HAVE_LLABS)
endif ()

set(LIBCFUNK_DECLARE_LLABS "1" CACHE STRING "")

if (NOT HAVE_LLABS OR LIBCFUNK_REPLACE_LLABS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/llabs.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-llabs.cmake)
endif ()

