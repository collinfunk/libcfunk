
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("fdopen" "stdio.h" HAVE_FDOPEN)
endif ()

if (NOT HAVE_FDOPEN)
  message(FATAL_ERROR "No implementation of 'fdopen' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fdopen.cmake)
endif ()

