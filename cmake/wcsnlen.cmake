
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

check_c_symbol(wcsnlen "wchar.h")

set(LIBCFUNK_DECLARE_WCSNLEN "1" CACHE INTERNAL "")

if (NOT HAVE_WCSNLEN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcsnlen.c
  )
endif ()
