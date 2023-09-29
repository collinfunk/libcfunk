
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

check_c_symbol(wmemcmp "wchar.h")

set(LIBCFUNK_DECLARE_WMEMCMP "1" CACHE INTERNAL "")

if (NOT HAVE_WMEMCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wmemcmp.c
  )
endif ()
