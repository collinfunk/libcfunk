
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcsspn" "wchar.h" HAVE_WCSSPN)
endif ()

set(LIBCFUNK_DECLARE_WCSSPN "1" CACHE STRING "")

if (NOT HAVE_WCSSPN OR LIBCFUNK_REPLACE_WCSSPN)
  include($CACHE{LIBCFUNK_MODULE_DIR}/wcschr.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcsspn.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-wcsspn.cmake)
endif ()

