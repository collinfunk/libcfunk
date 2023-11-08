
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("tss_delete" "threads.h" HAVE_TSS_DELETE)
endif ()

set(LIBCFUNK_DECLARE_TSS_DELETE "1" CACHE STRING "")

if (NOT HAVE_TSS_DELETE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/tss_delete.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

