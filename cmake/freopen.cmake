
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("freopen" "stdio.h" HAVE_FREOPEN)
endif ()

if (NOT HAVE_FREOPEN)
  message(FATAL_ERROR "No implementation of 'freopen' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-freopen.cmake)
endif ()

