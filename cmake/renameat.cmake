
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("renameat" "stdio.h" HAVE_RENAMEAT)
endif ()

# TODO
if (NOT HAVE_RENAMEAT)
  message(FATAL_ERROR "No implementation of 'renameat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

