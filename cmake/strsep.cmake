
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strsep" "string.h" HAVE_STRSEP)
endif ()

set(LIBCFUNK_DECLARE_STRSEP "1" CACHE STRING "")

if (NOT HAVE_STRSEP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strsep.c
  )
endif ()
