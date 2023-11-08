
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("thrd_create" "threads.h" HAVE_THRD_CREATE)
endif ()

set(LIBCFUNK_DECLARE_THRD_CREATE "1" CACHE STRING "")

if (NOT HAVE_THRD_CREATE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/thrd_create.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-thrd_create.cmake)
endif ()

