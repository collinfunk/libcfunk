
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcschr" "wchar.h" HAVE_WCSCHR)
endif ()

set(LIBCFUNK_DECLARE_WCSCHR "1" CACHE STRING "")

if (NOT HAVE_WCSCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcschr.c
  )
endif ()
