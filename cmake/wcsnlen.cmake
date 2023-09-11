
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wcsnlen "wchar.h" HAVE_WCSNLEN)
else ()
  set(HAVE_WCSNLEN "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCSNLEN "1" CACHE INTERNAL "")

if (NOT HAVE_WCSNLEN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcsnlen.c
  )
endif ()
