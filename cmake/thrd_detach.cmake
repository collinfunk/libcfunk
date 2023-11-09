
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("thrd_detach" "threads.h" HAVE_THRD_DETACH)
endif ()

set(LIBCFUNK_DECLARE_THRD_DETACH "1" CACHE STRING "")

if (NOT HAVE_THRD_DETACH)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/thrd_detach.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-thrd_detatch.cmake)
endif ()

