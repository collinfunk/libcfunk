
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("snprintf" "stdio.h" HAVE_SNPRINTF)
endif ()

if (NOT HAVE_SNPRINTF)
  message(FATAL_ERROR "Your system does not have an implementation for 'snprintf'.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

