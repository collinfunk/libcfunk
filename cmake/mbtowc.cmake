
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("mbtowc" "stdlib.h" HAVE_MBTOWC)
else ()
  set(HAVE_MBTOWC "" CACHE INTERNAL "")
endif ()

if (NOT HAVE_MBTOWC)
  message(FATAL_ERROR "No implementation of 'mbtowc' for your system.")
endif ()

