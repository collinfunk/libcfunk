
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("fwrite" "stdio.h" HAVE_FWRITE)
endif ()

if (NOT HAVE_FWRITE)
  message(FATAL_ERROR "No implementation of 'fwrite' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fwrite.cmake)
endif ()

