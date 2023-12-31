
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcscpy" "wchar.h" HAVE_WCSCPY)
endif ()

set(LIBCFUNK_DECLARE_WCSCPY "1" CACHE STRING "")

if (NOT HAVE_WCSCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcscpy.c
  )
endif ()
