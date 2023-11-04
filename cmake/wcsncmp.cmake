
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcsncmp" "wchar.h" HAVE_WCSNCMP)
endif ()

set(LIBCFUNK_DECLARE_WCSNCMP "1" CACHE STRING "")

if (NOT HAVE_WCSNCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcsncmp.c
  )
endif ()

