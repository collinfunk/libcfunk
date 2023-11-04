
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wcsdup "wchar.h" HAVE_WCSDUP)
endif ()

set(LIBCFUNK_DECLARE_WCSDUP "1" CACHE STRING "")

if (NOT HAVE_WCSDUP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcsdup.c
  )
endif ()
