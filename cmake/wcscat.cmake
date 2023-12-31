
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcscat" "wchar.h" HAVE_WCSCAT)
endif ()

set(LIBCFUNK_DECLARE_WCSCAT "1" CACHE STRING "")

if (NOT HAVE_WCSCAT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcscat.c
  )
endif ()
