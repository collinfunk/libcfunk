
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strcspn" "string.h" HAVE_STRCSPN)
endif ()

set(LIBCFUNK_DECLARE_STRCSPN "1" CACHE STRING "")

if (NOT HAVE_STRCSPN OR LIBCFUNK_REPLACE_STRCSPN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strcspn.c
  )
endif ()
