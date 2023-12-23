
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("strftime" "time.h" HAVE_STRFTIME)
endif ()

# TODO
if (NOT HAVE_STRFTIME)
  message(FATAL_ERROR "No implementation of 'strftime' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

