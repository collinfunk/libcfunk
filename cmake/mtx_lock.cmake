
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("mtx_lock" "threads.h" HAVE_MTX_LOCK)
endif ()

set(LIBCFUNK_DECLARE_MTX_LOCK "1" CACHE STRING "")

if (NOT HAVE_MTX_LOCK)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mtx_lock.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

