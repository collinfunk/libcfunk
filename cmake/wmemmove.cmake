
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

check_c_symbol(wmemmove "wchar.h")

set(LIBCFUNK_DECLARE_WMEMMOVE "1" CACHE INTERNAL "")

if (NOT HAVE_WMEMMOVE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wmemmove.c
  )
endif ()
