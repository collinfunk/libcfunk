
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("fopen" "stdio.h" HAVE_FOPEN)
endif ()

if (NOT HAVE_FOPEN)
  message(FATAL_ERROR "No implementation of 'fopen' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fopen.cmake)
endif ()

