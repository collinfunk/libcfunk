
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("thrd_exit" "threads.h" HAVE_THRD_EXIT)
endif ()

set(LIBCFUNK_DECLARE_THRD_EXIT "1" CACHE STRING "")

if (NOT HAVE_THRD_EXIT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/thrd_exit.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

