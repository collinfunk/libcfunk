
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("mblen" "stdlib.h" HAVE_MBLEN)
else ()
  set(HAVE_MBLEN "" CACHE INTERNAL "")
endif ()

if (NOT HAVE_MBLEN)
  message(FATAL_ERROR "No implementation of 'mblen' for your system.")
endif ()

