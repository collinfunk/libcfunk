
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wmemchr" "wchar.h" HAVE_WMEMCHR)
endif ()

set(LIBCFUNK_DECLARE_WMEMCHR "1" CACHE STRING "")

if (NOT HAVE_WMEMCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wmemchr.c
  )
endif ()
