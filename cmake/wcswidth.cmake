
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/wcwidth.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcswidth" "wchar.h" HAVE_WCSWIDTH)
else ()
  set(HAVE_WCSWIDTH "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCSWIDTH "1" CACHE INTERNAL "")

if (NOT HAVE_WCSWIDTH)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcswidth.c
  )
endif ()

