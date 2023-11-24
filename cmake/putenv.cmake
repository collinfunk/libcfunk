
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("putenv" "stdlib.h" HAVE_PUTENV)
endif ()

set(LIBCFUNK_DECLARE_PUTENV "1" CACHE STRING "")

if (NOT HAVE_PUTENV OR LIBCFUNK_REPLACE_PUTENV)
  include($CACHE{LIBCFUNK_MODULE_DIR}/environ.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/putenv.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-putenv.cmake)
endif ()

