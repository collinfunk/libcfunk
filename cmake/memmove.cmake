
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("memmove" "string.h" HAVE_MEMMOVE)
endif ()

set(LIBCFUNK_DECLARE_MEMMOVE "1" CACHE STRING "")

if (NOT HAVE_MEMMOVE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/memmove.c
  )
endif ()
