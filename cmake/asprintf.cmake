
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("asprintf" "stdio.h" HAVE_ASPRINTF)
endif ()

# TODO
if (NOT HAVE_ASPRINTF)
  message(FATAL_ERROR "No implementation of 'asprintf' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

