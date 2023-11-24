
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("unsetenv" "stdlib.h" HAVE_UNSETENV)
endif ()

# Check for old systems which have no return value.
if (HAVE_UNSETENV)
  check_c_source_compiles("
  #include <stdlib.h>

  extern int unsetenv (const char *name);

  int
  main (void)
  {
    return 0;
  }" UNSETENV_HAS_POSIX_PROTOTYPE)
  # Replace it with a POSIX compatible prototype.
  if (NOT UNSETENV_HAS_POSIX_PROTOTYPE)
    set(LIBCFUNK_REPLACE_UNSETENV "1" CACHE STRING "")
  endif ()
endif ()

set(LIBCFUNK_DECLARE_UNSETENV "1" CACHE STRING "")

if (NOT HAVE_UNSETENV OR LIBCFUNK_REPLACE_UNSETENV)
  include($CACHE{LIBCFUNK_MODULE_DIR}/environ.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strchr.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/getenv.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strncmp.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/unsetenv.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-unsetenv.cmake)
endif ()

