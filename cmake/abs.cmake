
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("abs" "stdlib.h" HAVE_ABS)
endif ()

set(LIBCFUNK_DECLARE_ABS "1" CACHE STRING "")

if (NOT HAVE_ABS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/abs.c
  )
endif ()
