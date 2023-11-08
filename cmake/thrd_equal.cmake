
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("thrd_equal" "threads.h" HAVE_THRD_EQUAL)
endif ()

set(LIBCFUNK_DECLARE_THRD_EQUAL "1" CACHE INTERNAL "")

if (NOT HAVE_THRD_EQUAL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/thrd_equal.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-thrd_equal.cmake)
endif ()

