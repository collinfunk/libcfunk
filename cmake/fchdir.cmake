
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("fchdir" "unistd.h" HAVE_FCHDIR)
else ()
  set(HAVE_FCHDIR "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_FCHDIR "1" CACHE INTERNAL "")

if (NOT HAVE_FCHDIR)
  # We assume that if 'fchdir' is not provided it is impossible to implement
  # without changing how other functions work. See 'fchdir.c' for why it
  # cannot be easily implemented on Windows.
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fchdir.c
  )
endif ()


