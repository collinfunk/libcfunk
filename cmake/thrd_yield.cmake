
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sched_yield.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("thrd_yield" "threads.h" HAVE_THRD_YIELD)
endif ()

set(LIBCFUNK_DECLARE_THRD_YIELD "1" CACHE STRING "")

if (NOT HAVE_THRD_YIELD)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/thrd_yield.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-thrd_yield.cmake)
endif ()

