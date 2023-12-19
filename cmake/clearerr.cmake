
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("clearerr" "stdio.h" HAVE_CLEARERR)
endif ()

if (NOT HAVE_CLEARERR)
  message(FATAL_ERROR "No implementation of 'clearerr' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-clearerr.cmake)
endif ()

