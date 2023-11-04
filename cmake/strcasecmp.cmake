
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("strcasecmp" "strings.h" HAVE_STRCASECMP)
endif ()

set(LIBCFUNK_DECLARE_STRCASECMP "1" CACHE STRING "")

if (NOT HAVE_STRCASECMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strcasecmp.c
  )
endif ()

