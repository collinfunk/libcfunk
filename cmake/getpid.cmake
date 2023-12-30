
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("getpid" "unistd.h" HAVE_GETPID)
endif ()

# Not really much we can do.
if (NOT HAVE_GETPID)
  message(FATAL_ERROR "No implementation of 'getpid' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getpid.cmake)
endif ()

