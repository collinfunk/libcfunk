
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("cnd_init" "threads.h" HAVE_CND_INIT)
endif ()

set(LIBCFUNK_DECLARE_CND_INIT "1" CACHE STRING "")

if (NOT HAVE_CND_INIT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/cnd_init.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-cnd_init.cmake)
endif ()

