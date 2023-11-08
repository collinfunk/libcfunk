
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("cnd_broadcast" "threads.h" HAVE_CND_BROADCAST)
endif ()

set(LIBCFUNK_DECLARE_CND_BROADCAST "1" CACHE STRING "")

if (NOT HAVE_CND_BROADCAST)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/cnd_broadcast.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()
