
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("strncasecmp" "strings.h" HAVE_STRNCASECMP)
endif ()

set(LIBCFUNK_DECLARE_STRNCASECMP "1" CACHE STRING "")

if (NOT HAVE_STRNCASECMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strncasecmp.c
  )
endif ()

