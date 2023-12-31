
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswblank" "wctype.h" HAVE_ISWBLANK)
endif ()

set(LIBCFUNK_DECLARE_ISWBLANK "1" CACHE STRING "")

if (NOT HAVE_ISWBLANK)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswblank.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-iswblank.cmake)
endif ()

