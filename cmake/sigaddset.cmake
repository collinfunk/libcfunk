
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

if (HAVE_SIGNAL_H)
  check_symbol_exists("sigaddset" "signal.h" HAVE_SIGADDSET)
else ()
  set(HAVE_SIGADDSET "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_SIGADDSET "1" CACHE INTERNAL "")

if (NOT HAVE_SIGADDSET)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/sigaddset.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sigaddset.cmake)
endif ()

