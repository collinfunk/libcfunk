
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/wmemcpy.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wmempcpy" "wchar.h" HAVE_WMEMPCPY)
else ()
  set(HAVE_WMEMPCPY "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WMEMPCPY "1" CACHE INTERNAL "")

if (NOT HAVE_WMEMPCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wmempcpy.c
  )
endif ()
