
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("time" "time.h" HAVE_TIME)
endif ()

if (NOT HAVE_TIME)
  message(FATAL_ERROR "No implementation of 'time' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-time.cmake)
endif ()

