
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strncmp" "string.h" HAVE_STRNCMP)
endif ()

set(LIBCFUNK_DECLARE_STRNCMP "1" CACHE STRING "")

if (NOT HAVE_STRNCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strncmp.c
  )
endif ()
