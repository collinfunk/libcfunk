
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("mtx_trylock" "threads.h" HAVE_MTX_TRYLOCK)
endif ()

set(LIBCFUNK_DECLARE_MTX_TRYLOCK "1" CACHE STRING "")

if (NOT HAVE_MTX_TRYLOCK)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mtx_trylock.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

