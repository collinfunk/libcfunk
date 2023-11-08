
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("mtx_timedlock" "threads.h" HAVE_MTX_TIMEDLOCK)
endif ()

set(LIBCFUNK_DECLARE_MTX_TIMEDLOCK "1" CACHE STRING "")

if (NOT HAVE_MTX_TIMEDLOCK)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mtx_timedlock.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

