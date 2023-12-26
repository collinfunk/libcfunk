
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("setvbuf" "stdio.h" HAVE_SETVBUF)
endif ()

# TODO
if (NOT HAVE_SETVBUF)
  message(FATAL_ERROR "No implementation of 'setvbuf' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

