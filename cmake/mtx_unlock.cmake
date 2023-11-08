
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("mtx_unlock" "threads.h" HAVE_MTX_UNLOCK)
endif ()

set(LIBCFUNK_DECLARE_MTX_UNLOCK "1" CACHE STRING "")

if (NOT HAVE_MTX_UNLOCK)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mtx_unlock.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

