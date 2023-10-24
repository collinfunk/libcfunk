
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/towlower.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcsncasecmp" "wchar.h" HAVE_WCSNCASECMP)
else ()
  set(HAVE_WCSNCASECMP "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCSNCASECMP "1" CACHE INTERNAL "")

if (NOT HAVE_WCSNCASECMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcsncasecmp.c
  )
endif ()

