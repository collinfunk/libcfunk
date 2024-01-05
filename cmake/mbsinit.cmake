
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("mbsinit" "wchar.h" HAVE_MBSINIT)
endif ()

# TODO
if (NOT HAVE_MBSINIT)
  message(FATAL_ERROR "No implementation of 'mbsinit' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-mbsinit.cmake)
endif ()

