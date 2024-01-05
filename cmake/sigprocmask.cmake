
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

if (HAVE_SIGNAL_H)
  check_symbol_exists("sigprocmask" "signal.h" HAVE_SIGPROCMASK)
endif ()

# TODO
if (NOT HAVE_SIGPROCMASK)
  message(FATAL_ERROR "No implementation of 'sigprocmask' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sigprocmask.cmake)
endif ()

