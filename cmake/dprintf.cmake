
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("dprintf" "stdio.h" HAVE_DPRINTF)
endif ()

# TODO
if (NOT HAVE_DPRINTF)
  message(FATAL_ERROR "No implementation of 'dprintf' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

