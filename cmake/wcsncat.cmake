
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcsncat" "wchar.h" HAVE_WCSNCAT)
endif ()

set(LIBCFUNK_DECLARE_WCSNCAT "1" CACHE STRING "")

if (NOT HAVE_WCSNCAT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcsncat.c
  )
endif ()

