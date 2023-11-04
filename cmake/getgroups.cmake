
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("getgroups" "unistd.h" HAVE_GETGROUPS)
endif ()

set(LIBCFUNK_DECLARE_GETGROUPS "1" CACHE STRING "")

if (NOT HAVE_GETGROUPS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getgroups.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getgroups.cmake)
endif ()
