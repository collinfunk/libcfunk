
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcrtomb" "wchar.h" HAVE_WCRTOMB)
endif ()

# TODO
if (NOT HAVE_WCRTOMB)
  message(FATAL_ERROR "No implementation of 'wcrtomb' for your system.")
endif ()
