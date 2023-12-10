
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("chown" "unistd.h" HAVE_CHOWN)
endif ()

set(LIBCFUNK_DECLARE_CHOWN "1" CACHE STRING "")

if (NOT HAVE_CHOWN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/chown.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-chown.cmake)
endif ()
