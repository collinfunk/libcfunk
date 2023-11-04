
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("close" "unistd.h" HAVE_CLOSE)
  check_symbol_exists("_close" "unistd.h" HAVE__CLOSE)
endif ()

set(LIBCFUNK_DECLARE_CLOSE "1" CACHE INTERNAL "")

if (NOT HAVE_CLOSE)
  if (NOT HAVE__CLOSE)
    message(FATAL_ERROR "No implementation of 'close' on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/close.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-close.cmake)
endif ()

