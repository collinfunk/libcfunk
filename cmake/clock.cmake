
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("clock" "time.h" HAVE_CLOCK)
endif ()

# TODO
if (NOT HAVE_CLOCK)
  message(FATAL_ERROR "No implementation of 'clock' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

