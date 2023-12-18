
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("tempnam" "stdio.h" HAVE_TEMPNAM)
endif ()

if (NOT HAVE_TEMPNAM)
  message(FATAL_ERROR "No implementation of 'tempnam' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-tempnam.cmake)
endif ()

