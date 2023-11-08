
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("tss_create" "threads.h" HAVE_TSS_CREATE)
endif ()

set(LIBCFUNK_DECLARE_TSS_CREATE "1" CACHE STRING "")

if (NOT HAVE_TSS_CREATE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/tss_create.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

