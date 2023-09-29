
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

check_c_symbol("atexit" "stdlib.h")
check_c_symbol("on_exit" "stdlib.h")

set(LIBCFUNK_DECLARE_ATEXIT "1" CACHE INTERNAL "")

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
