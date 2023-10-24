
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("wcstombs" "stdlib.h" HAVE_WCSTOMBS)
else ()
  set(HAVE_WCSTOMBS "" CACHE INTERNAL "")
endif ()

if (NOT HAVE_WCSTOMBS)
  message(FATAL_ERROR "No implementation for 'wcstombs' for your system.")
endif ()

