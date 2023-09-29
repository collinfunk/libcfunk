
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

check_c_symbol(wmemset "wchar.h")

set(LIBCFUNK_DECLARE_WMEMSET "1" CACHE INTERNAL "")

if (NOT HAVE_WMEMSET)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wmemset.c
  )
endif ()
