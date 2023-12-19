
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("feof" "stdio.h" HAVE_FEOF)
endif ()

if (NOT HAVE_FEOF)
  message(FATAL_ERROR "No implementation of 'feof' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-feof.cmake)
endif ()

