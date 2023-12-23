
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("difftime" "time.h" HAVE_DIFFTIME)
endif ()

# TODO
if (NOT HAVE_DIFFTIME)
  message(FATAL_ERROR "No implementation of 'difftime' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

