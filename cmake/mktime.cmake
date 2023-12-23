
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("mktime" "time.h" HAVE_MKTIME)
endif ()

# TODO
if (NOT HAVE_MKTIME)
  message(FATAL_ERROR "No implementation of 'mktime' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

