
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("call_once" "threads.h" HAVE_CALL_ONCE)
endif ()

set(LIBCFUNK_DECLARE_CALL_ONCE "1" CACHE STRING "")

if (NOT HAVE_CALL_ONCE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/call_once.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-call_once.cmake)
endif ()

