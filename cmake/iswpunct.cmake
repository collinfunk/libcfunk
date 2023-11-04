
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswpunct" "wctype.h" HAVE_ISWPUNCT)
endif ()

set(LIBCFUNK_DECLARE_ISWPUNCT "1" CACHE INTERNAL "")

if (NOT HAVE_ISWPUNCT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswpunct.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-iswpunct.cmake)
endif ()

