
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/towlower.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcscasecmp" "wchar.h" HAVE_WCSCASECMP)
endif ()

set(LIBCFUNK_DECLARE_WCSCASECMP "1" CACHE STRING "")

if (NOT HAVE_WCSCASECMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcscasecmp.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-wcscasecmp.cmake)
endif ()

