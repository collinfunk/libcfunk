
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

if (HAVE_SIGNAL_H)
  check_symbol_exists("sigfillset" "signal.h" HAVE_SIGFILLSET)
endif ()

set(LIBCFUNK_DECLARE_SIGFILLSET "1" CACHE STRING "")

if (NOT HAVE_SIGFILLSET)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/sigfillset.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sigfillset.cmake)
endif ()

