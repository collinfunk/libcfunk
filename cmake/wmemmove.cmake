
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wmemmove "wchar.h" HAVE_WMEMMOVE)
else ()
  set(HAVE_WMEMMOVE "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WMEMMOVE "1" CACHE INTERNAL "")

if (NOT HAVE_WMEMMOVE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wmemmove.c
  )
endif ()
