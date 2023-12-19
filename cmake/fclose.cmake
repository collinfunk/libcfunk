
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("fclose" "stdio.h" HAVE_FCLOSE)
endif ()

if (NOT HAVE_FCLOSE)
  message(FATAL_ERROR "No implementation of 'fclose' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fclose.cmake)
endif ()

