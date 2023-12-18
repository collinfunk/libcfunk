
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("tmpfile" "stdio.h" HAVE_TMPFILE)
endif ()

if (NOT HAVE_TMPFILE)
  message(FATAL_ERROR "No implementation for 'tmpfile' on your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-tmpfile.cmake)
endif ()

