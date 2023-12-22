
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("l64a_r" "stdlib.h" HAVE_L64A_R)
endif ()

set(LIBCFUNK_DECLARE_L64A_R "1" CACHE STRING "")

if (NOT HAVE_L64A_R OR LIBCFUNK_REPLACE_L64A_R)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/l64a_r.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-l64a_r.cmake)
endif ()

