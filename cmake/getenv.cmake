
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("getenv" "stdlib.h" HAVE_GETENV)
endif ()

set(LIBCFUNK_DECLARE_GETENV "1" CACHE STRING "")

if (NOT HAVE_GETENV OR LIBCFUNK_REPLACE_GETENV)
  include($CACHE{LIBCFUNK_MODULE_DIR}/environ.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strncmp.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getenv.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getenv.cmake)
endif ()

