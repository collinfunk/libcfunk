
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswalpha" "wctype.h" HAVE_ISWALPHA)
endif ()

set(LIBCFUNK_DECLARE_ISWALPHA "1" CACHE STRING "")

if (NOT HAVE_ISWALPHA)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswalpha.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-iswalpha.cmake)
endif ()

