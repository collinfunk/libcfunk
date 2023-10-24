
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/wcsnlen.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/wmemcpy.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/wmemset.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcpncpy" "wchar.h" HAVE_WCPNCPY)
else ()
  set(HAVE_WCPNCPY "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCPNCPY "1" CACHE INTERNAL "")

if (NOT HAVE_WCPNCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcpncpy.c
  )
endif ()

