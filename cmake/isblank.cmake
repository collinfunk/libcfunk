
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("isblank" "ctype.h" HAVE_ISBLANK)
endif ()

set(LIBCFUNK_DECLARE_ISBLANK "1" CACHE STRING "")

if (NOT HAVE_ISBLANK)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isblank.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-isblank.cmake)
endif ()

