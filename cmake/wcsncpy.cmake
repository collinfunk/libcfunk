
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcsncpy" "wchar.h" HAVE_WCSNCPY)
endif ()

set(LIBCFUNK_DECLARE_WCSNCPY "1" CACHE STRING "")

if (NOT HAVE_WCSNCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcsncpy.c
  )
endif ()

