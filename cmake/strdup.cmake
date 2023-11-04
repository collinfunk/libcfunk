
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strdup" "string.h" HAVE_STRDUP)
endif ()

set(LIBCFUNK_DECLARE_STRDUP "1" CACHE STRING "")

if (NOT HAVE_STRDUP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strdup.c
  )
endif ()
