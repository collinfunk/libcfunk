
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtoul" "stdlib.h" HAVE_STRTOUL)
endif ()

set(LIBCFUNK_DECLARE_STRTOUL "1" CACHE STRING "")

if (NOT HAVE_STRTOUL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoul.c
  )
endif ()

