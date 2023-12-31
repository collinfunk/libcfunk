
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("calloc" "stdlib.h" HAVE_CALLOC)
else ()
  set(HAVE_CALLOC "" CACHE STRING "")
endif ()

# Should never happen.
if (NOT HAVE_CALLOC)
  message(FATAL_ERROR "Could not find the calloc function on your system.")
endif ()

# FIXME: Figure out a good way to handle this.
if (CMAKE_CROSSCOMPILING AND NOT CMAKE_CROSSCOMPILING_EMULATOR)
  set(CALLOC_0_0_RETURNS_NONNULL "" CACHE STRING "")
else ()
  check_c_source_runs("
  #include <stdlib.h>

  #ifndef NULL
  #  define NULL ((void *) 0)
  #endif

  int
  main (void)
  {
    char *ptr;
    int status;
    ptr = (char *) calloc (0, 0);
    if (ptr == NULL)
      status = 1;
    else /* Make sure p[0] can be accessed */
      {
        *ptr = 1;
        status = *ptr == 1 ? 0 : 1;
      }
    return status;
  }" CALLOC_0_0_RETURNS_NONNULL)
endif ()

set(LIBCFUNK_DECLARE_CALLOC "1" CACHE STRING "")

if (NOT CALLOC_0_0_RETURNS_NONNULL)
  set(LIBCFUNK_REPLACE_CALLOC "1" CACHE STRING "")
endif ()

if (LIBCFUNK_REPLACE_CALLOC)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/calloc.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-calloc.cmake)
endif ()
