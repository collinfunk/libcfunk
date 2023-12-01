
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcscspn" "wchar.h" HAVE_WCSCSPN)
endif ()

set(LIBCFUNK_DECLARE_WCSCSPN "1" CACHE STRING "")

if (NOT HAVE_WCSCSPN OR LIBCFUNK_REPLACE_WCSCSPN)
  include($CACHE{LIBCFUNK_MODULE_DIR}/wcschr.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcscspn.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-wcscspn.cmake)
endif ()

