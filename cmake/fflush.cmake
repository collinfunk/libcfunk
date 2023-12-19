
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("fflush" "stdio.h" HAVE_FFLUSH)
endif ()

if (NOT HAVE_FFLUSH)
  message(FATAL_ERROR "No implementation of 'fflush' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fflush.cmake)
endif ()

