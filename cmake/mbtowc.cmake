
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/mbrtowc.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/memset.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("mbtowc" "stdlib.h" HAVE_MBTOWC)
endif ()

set(LIBCFUNK_DECLARE_MBTOWC "1" CACHE STRING "")

if (NOT HAVE_MBTOWC)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mbtowc.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-mbtowc.cmake)
endif ()

