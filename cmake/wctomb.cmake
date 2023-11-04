
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/wcrtomb.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/memset.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("wctomb" "stdlib.h" HAVE_WCTOMB)
endif ()

set(LIBCFUNK_DECLARE_WCTOMB "1" CACHE INTERNAL "")

if (NOT HAVE_WCTOMB)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wctomb.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-wctomb.cmake)
endif ()

