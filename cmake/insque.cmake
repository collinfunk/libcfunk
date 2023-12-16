
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/search-h.cmake)

if (HAVE_SEARCH_H)
  check_symbol_exists("insque" "search.h" HAVE_INSQUE)
endif ()

set(LIBCFUNK_DECLARE_INSQUE "1" CACHE STRING "")

if (NOT HAVE_INSQUE OR LIBCFUNK_REPLACE_INSQUE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/insque.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-insque.cmake)
endif ()

