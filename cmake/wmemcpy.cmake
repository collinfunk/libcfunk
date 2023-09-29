
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

check_c_symbol(wmemcpy "wchar.h")

set(LIBCFUNK_DECLARE_WMEMCPY "1" CACHE INTERNAL "")

if (NOT HAVE_WMEMCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wmemcpy.c
  )
endif ()
