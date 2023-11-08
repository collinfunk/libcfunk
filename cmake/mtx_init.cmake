
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("mtx_init" "threads.h" HAVE_MTX_INIT)
endif ()

set(LIBCFUNK_DECLARE_MTX_INIT "1" CACHE STRING "")

if (NOT HAVE_MTX_INIT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mtx_init.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-mtx_init.cmake)
endif ()

