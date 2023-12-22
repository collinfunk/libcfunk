
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("ptsname" "stdlib.h" HAVE_PTSNAME)
endif ()

# TODO
if (NOT HAVE_PTSNAME)
  message(FATAL_ERROR "No implementation of 'ptsname' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ptsname.cmake)
endif ()

