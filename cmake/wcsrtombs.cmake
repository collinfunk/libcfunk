
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcsrtombs" "wchar.h" HAVE_WCSRTOMBS)
endif ()

# TODO
if (NOT HAVE_WCSRTOMBS)
  message(FATAL_ERROR "No implementation of 'wcsrtombs' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

