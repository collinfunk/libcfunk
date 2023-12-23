
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("strptime" "time.h" HAVE_STRPTIME)
endif ()

# TODO
if (NOT HAVE_STRPTIME)
  message(FATAL_ERROR "No implementation of 'strptime' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

