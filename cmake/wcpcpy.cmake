
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

check_c_symbol(wcpcpy "wchar.h")
  
set(LIBCFUNK_DECLARE_WCPCPY "1" CACHE INTERNAL "")

if (NOT HAVE_WCPCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcpcpy.c
  )
endif ()
