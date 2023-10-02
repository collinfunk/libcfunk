
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("malloc" "stdlib.h" HAVE_MALLOC)
else ()
  set(HAVE_MALLOC "" CACHE INTERNAL "")
endif ()

# Should never happen.
if (NOT HAVE_MALLOC)
  message(FATAL_ERROR "Could not find the malloc function on your system.")
endif ()

# FIXME: Figure out a good way to handle this.
if (CMAKE_CROSSCOMPILING AND NOT CMAKE_CROSSCOMPILING_EMULATOR)
  set(MALLOC_0_RETURNS_NONNULL "" CACHE INTERNAL "")
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
    ptr = (char *) malloc (0);
    if (ptr == NULL)
      status = 1;
    else /* Make sure p[0] can be accessed */
      {
        *ptr = 1;
        status = *ptr == 1 ? 0 : 1;
      }
    return status;
  }" MALLOC_0_RETURNS_NONNULL)
endif ()

set(LIBCFUNK_DECLARE_MALLOC "1" CACHE INTERNAL "")

if (NOT MALLOC_0_RETURNS_NONNULL)
  set(LIBCFUNK_REPLACE_MALLOC "1" CACHE INTERNAL "")
endif ()

if (LIBCFUNK_REPLACE_MALLOC)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/malloc.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-malloc.cmake)
endif ()
