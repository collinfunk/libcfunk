
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wmemcpy" "wchar.h" HAVE_WMEMCPY)
endif ()

set(LIBCFUNK_DECLARE_WMEMCPY "1" CACHE STRING "")

if (NOT HAVE_WMEMCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wmemcpy.c
  )
endif ()
