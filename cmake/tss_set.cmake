
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/threads-h.cmake)

if (HAVE_THREADS_H)
  check_symbol_exists("tss_set" "threads.h" HAVE_TSS_SET)
endif ()

set(LIBCFUNK_DECLARE_TSS_SET "1" CACHE INTERNAL "")

if (NOT HAVE_TSS_SET)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/tss_set.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

