
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("fchdir" "unistd.h" HAVE_FCHDIR)
endif ()

set(LIBCFUNK_DECLARE_FCHDIR "1" CACHE STRING "")

if (NOT HAVE_FCHDIR)
  # We assume that if 'fchdir' is not provided it is impossible to implement
  # without changing how other functions work. See 'fchdir.c' for why it
  # cannot be easily implemented on Windows.
  include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fchdir.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fchdir.cmake)
endif ()

