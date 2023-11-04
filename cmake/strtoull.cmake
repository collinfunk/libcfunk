
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtoull" "stdlib.h" HAVE_STRTOULL)
endif ()

set(LIBCFUNK_DECLARE_STRTOULL "1" CACHE INTERNAL "")

if (NOT HAVE_STRTOULL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoull.c
  )
endif ()

