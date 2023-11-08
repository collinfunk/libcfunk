
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("thrd_current" "threads.h" HAVE_THRD_CURRENT)
endif ()

set(LIBCFUNK_DECLARE_THRD_CURRENT "1" CACHE STRING "")

if (NOT HAVE_THRD_CURRENT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/thrd_current.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-thrd_current.cmake)
endif ()

