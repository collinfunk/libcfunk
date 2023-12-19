
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("perror" "stdio.h" HAVE_PERROR)
endif ()

if (NOT HAVE_PERROR)
  message(FATAL_ERROR "No implementation of 'perror' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-perror.cmake)
endif ()

