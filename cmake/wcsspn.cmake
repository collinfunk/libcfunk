
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcsspn" "wchar.h" HAVE_WCSSPN)
endif ()

set(LIBCFUNK_DECLARE_WCSSPN "1" CACHE INTERNAL "")

if (NOT HAVE_WCSSPN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcsspn.c
  )
endif ()
