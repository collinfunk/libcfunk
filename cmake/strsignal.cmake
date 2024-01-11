
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strsignal" "string.h" HAVE_STRSIGNAL)
endif ()

# TODO
if (NOT HAVE_STRSIGNAL)
  message(FATAL_ERROR "No implementation of 'strsignal' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strsignal.cmake)
endif ()

