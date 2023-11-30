
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("atol" "stdlib.h" HAVE_ATOL)
endif ()

set(LIBCFUNK_DECLARE_ATOL "1" CACHE STRING "")

if (NOT HAVE_ATOL)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strtol.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/atol.c
  )
endif ()
