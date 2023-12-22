
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("l64a" "stdlib.h" HAVE_L64A)
endif ()

set(LIBCFUNK_DECLARE_L64A "1" CACHE STRING "")

if (NOT HAVE_L64A OR LIBCFUNK_REPLACE_L64A)
  include($CACHE{LIBCFUNK_MODULE_DIR}/l64a_r.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/l64a.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-l64a.cmake)
endif ()

