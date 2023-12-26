
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("sprintf" "stdio.h" HAVE_SPRINTF)
endif ()

# TODO
if (NOT HAVE_SPRINTF)
  message(FATAL_ERROR "No implementation of 'sprintf' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

