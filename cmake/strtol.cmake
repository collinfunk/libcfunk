
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtol" "stdlib.h" HAVE_STRTOL)
endif ()

set(LIBCFUNK_DECLARE_STRTOL "1" CACHE INTERNAL "")

if (NOT HAVE_STRTOL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtol.c
  )
endif ()

