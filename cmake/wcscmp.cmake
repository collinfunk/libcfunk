
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcscmp" "wchar.h" HAVE_WCSCMP)
endif ()

set(LIBCFUNK_DECLARE_WCSCMP "1" CACHE STRING "")

if (NOT HAVE_WCSCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcscmp.c
  )
endif ()
