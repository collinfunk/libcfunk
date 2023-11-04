
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wmemcmp" "wchar.h" HAVE_WMEMCMP)
endif ()

set(LIBCFUNK_DECLARE_WMEMCMP "1" CACHE STRING "")

if (NOT HAVE_WMEMCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wmemcmp.c
  )
endif ()
