
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wcscspn "wchar.h" HAVE_WCSCSPN)
else ()
  set(HAVE_WCSCSPN "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCSCSPN "1" CACHE INTERNAL "")

if (NOT HAVE_WCSCSPN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcscspn.c
  )
endif ()