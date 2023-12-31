
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strncat" "string.h" HAVE_STRNCAT)
endif ()

set(LIBCFUNK_DECLARE_STRNCAT "1" CACHE STRING "")

if (NOT HAVE_STRNCAT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strncat.c
  )
endif ()
