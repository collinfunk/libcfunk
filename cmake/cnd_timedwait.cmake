
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("cnd_timedwait" "threads.h" HAVE_CND_TIMEDWAIT)
endif ()

set(LIBCFUNK_DECLARE_CND_TIMEDWAIT "1" CACHE STRING "")

if (NOT HAVE_CND_TIMEDWAIT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/cnd_timedwait.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()
