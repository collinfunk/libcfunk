
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("tmpnam_r" "stdio.h" HAVE_TMPNAM_R)
endif ()

# TODO
if (NOT HAVE_TMPNAM_R)
  message(FATAL_ERROR "No implementation of 'tmpnam_r' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-tmpnam_r.cmake)
endif ()

