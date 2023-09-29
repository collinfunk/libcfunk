
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

check_c_symbol(wmemchr "wchar.h")

set(LIBCFUNK_DECLARE_WMEMCHR "1" CACHE INTERNAL "")

if (NOT HAVE_WMEMCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wmemchr.c
  )
endif ()
