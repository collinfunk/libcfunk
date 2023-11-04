
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswprint" "wctype.h" HAVE_ISWPRINT)
endif ()

set(LIBCFUNK_DECLARE_ISWPRINT "1" CACHE INTERNAL "")

if (NOT HAVE_ISWPRINT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswprint.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-iswprint.cmake)
endif ()

