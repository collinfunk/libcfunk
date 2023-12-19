
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("fread" "stdio.h" HAVE_FREAD)
endif ()

if (NOT HAVE_FREAD)
  message(FATAL_ERROR "No implementation of 'fread' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fread.cmake)
endif ()

