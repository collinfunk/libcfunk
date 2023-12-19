
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("fgetpos" "stdio.h" HAVE_FGETPOS)
endif ()

if (NOT HAVE_FGETPOS)
  message(FATAL_ERROR "No implementation of 'fgetpos' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fgetpos.cmake)
endif ()

