
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcspbrk" "wchar.h" HAVE_WCSPBRK)
endif ()

set(LIBCFUNK_DECLARE_WCSPBRK "1" CACHE STRING "")

if (NOT HAVE_WCSPBRK)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcspbrk.c
  )
endif ()
