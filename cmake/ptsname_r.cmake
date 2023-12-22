
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("ptsname_r" "stdlib.h" HAVE_PTSNAME_R)
endif ()

if (NOT HAVE_PTSNAME_R)
  message(FATAL_ERROR "No implementation of 'ptsname_r' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ptsname_r.cmake)
endif ()

