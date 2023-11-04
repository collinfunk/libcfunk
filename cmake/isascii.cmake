
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("isascii" "ctype.h" HAVE_ISASCII)
endif ()

set(LIBCFUNK_DECLARE_ISASCII "1" CACHE STRING "")

if (NOT HAVE_ISASCII)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isascii.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

