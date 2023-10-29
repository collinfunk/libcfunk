
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/iswprint.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcwidth" "wchar.h" HAVE_WCWIDTH)
else ()
  set(HAVE_WCWIDTH "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCWIDTH "1" CACHE INTERNAL "")

if (NOT HAVE_WCWIDTH)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcwidth.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-wcwidth.cmake)
endif ()
