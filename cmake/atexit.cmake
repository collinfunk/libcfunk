
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("atexit" "stdlib.h" HAVE_ATEXIT)
  check_symbol_exists("on_exit" "stdlib.h" HAVE_ON_EXIT)
endif ()

set(LIBCFUNK_DECLARE_ATEXIT "1" CACHE STRING "")

if (NOT HAVE_ATEXIT)
  # Shouldn't ever happen but just make sure.
  if (NOT HAVE_ON_EXIT)
    message(FATAL_ERROR "You system does not provide `atexit' and \
it does not have the `on_exit' function to use as an alternative.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/atexit.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-atexit.cmake)
endif ()
