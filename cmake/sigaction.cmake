
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

if (HAVE_SIGNAL_H)
  check_symbol_exists("sigaction" "signal.h" HAVE_SIGACTION)
endif ()

if (NOT HAVE_SIGACTION)
  message(FATAL_ERROR "No implementation of 'sigaction' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sigaction.cmake)
endif ()

