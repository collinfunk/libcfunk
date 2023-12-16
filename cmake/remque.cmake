
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/search-h.cmake)

if (HAVE_SEARCH_H)
  check_symbol_exists("remque" "search.h" HAVE_REMQUE)
endif ()

set(LIBCFUNK_DECLARE_REMQUE "1" CACHE STRING "")

if (NOT HAVE_REMQUE OR LIBCFUNK_REPLACE_REMQUE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/remque.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-remque.cmake)
endif ()

