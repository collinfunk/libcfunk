
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("ferror" "stdio.h" HAVE_FERROR)
endif ()

if (NOT HAVE_FERROR)
  message(FATAL_ERROR "No implementation of 'ferror' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ferror.cmake)
endif ()

