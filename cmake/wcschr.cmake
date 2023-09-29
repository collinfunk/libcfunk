
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

check_c_symbol(wcschr "wchar.h")

set(LIBCFUNK_DECLARE_WCSCHR "1" CACHE INTERNAL "")

if (NOT HAVE_WCSCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcschr.c
  )
endif ()
