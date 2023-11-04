
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswspace" "wctype.h" HAVE_ISWSPACE)
endif ()

set(LIBCFUNK_DECLARE_ISWSPACE "1" CACHE INTERNAL "")

if (NOT HAVE_ISWSPACE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswspace.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-iswspace.cmake)
endif ()

