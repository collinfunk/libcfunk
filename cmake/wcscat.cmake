
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

check_c_symbol(wcscat "wchar.h")

set(LIBCFUNK_DECLARE_WCSCAT "1" CACHE INTERNAL "")

if (NOT HAVE_WCSCAT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcscat.c
  )
endif ()
