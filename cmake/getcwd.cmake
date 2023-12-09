
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_UNISTD_H)
  check_symbol_exists("getcwd" "unistd.h" HAVE_GETCWD)
  check_symbol_exists("_getcwd" "unistd.h" HAVE__GETCWD)
endif ()

# This might be possible on old systems.
if (NOT HAVE_GETCWD AND NOT HAVE__GETCWD)
  message(FATAL_ERROR "Do not have the getcwd function.")
endif ()

# FIXME: Figure out a good way to handle this.
if (CMAKE_CROSSCOMPILING AND NOT CMAKE_CROSSCOMPILING_EMULATOR)
  set(GETCWD_NULL_0_ALLOCATES_MEMORY "" CACHE STRING "")
else ()
  if (HAVE_GETCWD)
    set(GETCWD_FUNCTION "getcwd")
  else () # HAVE__GETCWD
    set(GETCWD_FUNCTION "_getcwd")
  endif ()
  check_c_source_runs("
  #include <stdlib.h>
  #include <unistd.h>

  #ifndef NULL
  #  define NULL ((void *) 0)
  #endif

  int
  main (void)
  {
    char *ptr = ${GETCWD_FUNCTION} (NULL, 0);
    if (ptr == NULL)
      return 1;
    free (ptr);
    return 0;
  }" GETCWD_NULL_0_ALLOCATES_MEMORY)
  unset(GETCWD_FUNCTION)
endif ()

set(LIBCFUNK_DECLARE_GETCWD "1" CACHE STRING "")

if (NOT GETCWD_NULL_0_ALLOCATES_MEMORY)
  set(LIBCFUNK_REPLACE_GETCWD "1" CACHE STRING "")
endif ()

if (NOT HAVE_GETCWD OR LIBCFUNK_REPLACE_GETCWD)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strdup.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getcwd.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getcwd.cmake)
endif ()

