
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("isspace" "ctype.h" HAVE_ISSPACE)
endif ()

set(LIBCFUNK_DECLARE_ISSPACE "1" CACHE STRING "")

if (NOT HAVE_ISSPACE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isspace.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

