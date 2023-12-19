
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("fsetpos" "stdio.h" HAVE_FSETPOS)
endif ()

if (NOT HAVE_FSETPOS)
  message(FATAL_ERROR "No implementation of 'fsetpos' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fsetpos.cmake)
endif ()

