
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/nanosleep.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("thrd_sleep" "threads.h" HAVE_THRD_SLEEP)
endif ()

set(LIBCFUNK_DECLARE_THRD_SLEEP "1" CACHE STRING "")

if (NOT HAVE_THRD_SLEEP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/thrd_sleep.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-thrd_sleep.cmake)
endif ()

