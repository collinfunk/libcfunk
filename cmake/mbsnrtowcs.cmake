
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("mbsnrtowcs" "wchar.h" HAVE_MBSNRTOWCS)
endif ()

# TODO
if (NOT HAVE_MBSNRTOWCS)
  message(FATAL_ERROR "No implementation of 'mbsnrtowcs' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

