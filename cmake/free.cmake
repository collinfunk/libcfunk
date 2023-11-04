
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("free" "stdlib.h" HAVE_FREE)
endif ()

# Should never happen.
if (NOT HAVE_FREE)
  message(FATAL_ERROR "Could not find the free function on your system.")
endif ()

# FIXME: Figure out a good way to handle this.
if (CMAKE_CROSSCOMPILING AND NOT CMAKE_CROSSCOMPILING_EMULATOR)
  set(FREE_NULL_IS_NOP "" CACHE INTERNAL "")
else ()
  check_c_source_runs("
  #include <stdlib.h>

  #ifndef NULL
  #  define NULL ((void *) 0)
  #endif

  int
  main (void)
  {
    char *ptr = NULL;
    free (ptr);
    return 0;
  }" FREE_NULL_IS_NOP)
endif ()

set(LIBCFUNK_DECLARE_FREE "1" CACHE INTERNAL "")

if (NOT FREE_NULL_IS_NOP)
  set(LIBCFUNK_REPLACE_FREE "1" CACHE INTERNAL "")
endif ()

if (LIBCFUNK_REPLACE_FREE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/free.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-free.cmake)
endif ()
