
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswgraph" "wctype.h" HAVE_ISWGRAPH)
endif ()

set(LIBCFUNK_DECLARE_ISWGRAPH "1" CACHE INTERNAL "")

if (NOT HAVE_ISWGRAPH)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswgraph.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-iswgraph.cmake)
endif ()

