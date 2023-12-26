
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("rename" "stdio.h" HAVE_RENAME)
endif ()

# TODO
if (NOT HAVE_RENAME)
  message(FATAL_ERROR "No implementation of 'rename' on your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

