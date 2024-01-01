
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("mbsrtowcs" "wchar.h" HAVE_MBSRTOWCS)
endif ()

if (NOT HAVE_MBSRTOWCS)
  message(FATAL_ERROR "No implementation of 'mbsrtowcs' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

