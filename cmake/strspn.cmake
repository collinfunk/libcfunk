
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strspn" "string.h" HAVE_STRSPN)
endif ()

set(LIBCFUNK_DECLARE_STRSPN "1" CACHE STRING "")

if (NOT HAVE_STRSPN OR LIBCFUNK_REPLACE_STRSPN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strspn.c
  )
endif ()
