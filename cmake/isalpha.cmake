
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("isalpha" "ctype.h" HAVE_ISALPHA)
endif ()

set(LIBCFUNK_DECLARE_ISALPHA "1" CACHE STRING "")

if (NOT HAVE_ISALPHA)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isalpha.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

