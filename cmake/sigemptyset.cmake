
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

if (HAVE_SIGNAL_H)
  check_symbol_exists("sigemptyset" "signal.h" HAVE_SIGEMPTYSET)
else ()
  set(HAVE_SIGEMPTYSET "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_SIGEMPTYSET "1" CACHE INTERNAL "")

if (NOT HAVE_SIGEMPTYSET)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/sigemptyset.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sigemptyset.cmake)
endif ()

