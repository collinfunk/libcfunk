
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("wctomb" "stdlib.h" HAVE_WCTOMB)
else ()
  set(HAVE_WCTOMB "" CACHE INTERNAL "")
endif ()

if (NOT HAVE_WCTOMB)
  message(FATAL_ERROR "No implementation for 'wctomb' for your system.")
endif ()

