
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

check_c_symbol(wcscmp "wchar.h")

set(LIBCFUNK_DECLARE_WCSCMP "1" CACHE INTERNAL "")

if (NOT HAVE_WCSCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcscmp.c
  )
endif ()
