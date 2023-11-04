
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

if (HAVE_SIGNAL_H)
  check_symbol_exists("sigismember" "signal.h" HAVE_SIGISMEMBER)
endif ()

set(LIBCFUNK_DECLARE_SIGISMEMBER "1" CACHE INTERNAL "")

if (NOT HAVE_SIGISMEMBER)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/sigismember.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sigismember.cmake)
endif ()

