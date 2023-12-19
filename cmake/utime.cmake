
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/utime-h.cmake)

if (HAVE_UTIME_H)
  check_symbol_exists("utime" "utime.h" HAVE_UTIME)
endif ()

# TODO
if (NOT HAVE_UTIME)
  message(FATAL_ERROR "No implementation of 'utime' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utime.cmake)
endif ()

