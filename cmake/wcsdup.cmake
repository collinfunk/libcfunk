
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

check_c_symbol(wcsdup "wchar.h")

set(LIBCFUNK_DECLARE_WCSDUP "1" CACHE INTERNAL "")

if (NOT HAVE_WCSDUP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcsdup.c
  )
endif ()
