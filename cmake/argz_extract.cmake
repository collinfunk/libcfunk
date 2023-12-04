
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/argz-h.cmake)

if (HAVE_ARGZ_H)
  check_symbol_exists("argz_extract" "argz.h" HAVE_ARGZ_EXTRACT)
endif ()

set(LIBCFUNK_DECLARE_ARGZ_EXTRACT "1" CACHE STRING "")

if (NOT HAVE_ARGZ_EXTRACT OR LIBCFUNK_REPLACE_ARGZ_EXTRACT)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/argz_extract.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-argz_extract.cmake)
endif ()

