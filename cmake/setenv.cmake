
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("setenv" "stdlib.h" HAVE_SETENV)
endif ()

set(LIBCFUNK_DECLARE_SETENV "1" CACHE STRING "")

if (NOT HAVE_SETENV OR LIBCFUNK_REPLACE_SETENV)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strchr.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strncmp.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/memcpy.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/environ.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/setenv.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-setenv.cmake)
endif ()

