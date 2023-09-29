
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

check_c_symbol(wcslen "wchar.h")

set(LIBCFUNK_DECLARE_WCSLEN "1" CACHE INTERNAL "")

if (NOT HAVE_WCSLEN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcslen.c
  )
endif ()
