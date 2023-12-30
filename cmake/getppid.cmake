
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("getppid" "unistd.h" HAVE_GETPPID)
endif ()

# TODO: Windows.
if (NOT HAVE_GETPPID)
  message(FATAL_ERROR "No implementation of 'getppid' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getppid.cmake)
endif ()

