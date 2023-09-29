
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

check_c_symbol(wcscpy "wchar.h")

set(LIBCFUNK_DECLARE_WCSCPY "1" CACHE INTERNAL "")

if (NOT HAVE_WCSCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcscpy.c
  )
endif ()
