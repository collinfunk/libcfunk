
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strncpy" "string.h" HAVE_STRNCPY)
endif ()

set(LIBCFUNK_DECLARE_STRNCPY "1" CACHE STRING "")

if (NOT HAVE_STRNCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strncpy.c
  )
endif ()
