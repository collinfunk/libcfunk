
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("tss_get" "threads.h" HAVE_TSS_GET)
endif ()

set(LIBCFUNK_DECLARE_TSS_GET "1" CACHE STRING "")

if (NOT HAVE_TSS_GET)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/tss_get.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

