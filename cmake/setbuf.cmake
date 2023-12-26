
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("setbuf" "stdio.h" HAVE_SETBUF)
endif ()

# TODO
if (NOT HAVE_SETBUF)
  message(FATAL_ERROR "No implementation of 'setbuf' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

