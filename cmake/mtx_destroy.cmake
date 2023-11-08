
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("mtx_destroy" "threads.h" HAVE_MTX_DESTROY)
endif ()

set(LIBCFUNK_DECLARE_MTX_DESTROY "1" CACHE STRING "")

if (NOT HAVE_MTX_DESTROY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mtx_destroy.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-mtx_destroy.cmake)
endif ()

