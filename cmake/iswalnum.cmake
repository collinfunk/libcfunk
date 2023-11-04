
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswalnum" "wctype.h" HAVE_ISWALNUM)
endif ()

set(LIBCFUNK_DECLARE_ISWALNUM "1" CACHE STRING "")

if (NOT HAVE_ISWALNUM)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswalnum.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-iswalnum.cmake)
endif ()

