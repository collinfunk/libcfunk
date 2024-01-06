
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

if (HAVE_SIGNAL_H)
  check_symbol_exists("signal" "signal.h" HAVE_SIGNAL)
endif ()

# TODO
if (NOT HAVE_SIGNAL)
  message(FATAL_ERROR "No implementation of 'signal' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-signal.cmake)
endif ()

