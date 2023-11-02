
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

if (HAVE_SIGNAL_H)
  check_symbol_exists("sigdelset" "signal.h" HAVE_SIGDELSET)
else ()
  set(HAVE_SIGDELSET "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_SIGDELSET "1" CACHE INTERNAL "")

if (NOT HAVE_SIGDELSET)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/sigdelset.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sigdelset.cmake)
endif ()

