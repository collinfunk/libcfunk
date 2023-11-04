
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("toascii" "ctype.h" HAVE_TOASCII)
endif ()

set(LIBCFUNK_DECLARE_TOASCII "1" CACHE STRING "")

if (NOT HAVE_TOASCII)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/toascii.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

