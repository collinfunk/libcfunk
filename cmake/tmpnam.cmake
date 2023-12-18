
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("tmpnam" "stdio.h" HAVE_TMPNAM)
endif ()

# TODO
if (NOT HAVE_TMPNAM)
  message(FATAL_ERROR "No implementation of 'tmpnam' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-tmpnam.cmake)
endif ()

