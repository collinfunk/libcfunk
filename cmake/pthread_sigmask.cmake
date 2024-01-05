
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

if (HAVE_SIGNAL_H)
  check_symbol_exists("pthread_sigmask" "signal.h" HAVE_PTHREAD_SIGMASK)
endif ()

# TODO
if (NOT HAVE_PTHREAD_SIGMASK)
  message(FATAL_ERROR "No implementation of 'pthread_sigmask' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-pthread_sigmask.cmake)
endif ()

