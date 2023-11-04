
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("bcopy" "strings.h" HAVE_BCOPY)
endif ()

set(LIBCFUNK_DECLARE_BCOPY "1" CACHE STRING "")

if (NOT HAVE_BCOPY OR LIBCFUNK_REPLACE_BCOPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/bcopy.c
  )
endif ()

