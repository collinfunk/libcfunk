
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists(wcslen "wchar.h" HAVE_WCSLEN)
else ()
  set(HAVE_WCSLEN "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCSLEN "1" CACHE INTERNAL "")

if (NOT HAVE_WCSLEN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcslen.c
  )
endif ()
