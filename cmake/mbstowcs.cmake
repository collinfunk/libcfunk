
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("mbstowcs" "stdlib.h" HAVE_MBSTOWCS)
endif ()

if (NOT HAVE_MBSTOWCS)
  message(FATAL_ERROR "No implementation of 'mbstowcs' for your system.")
endif ()

