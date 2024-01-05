
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("getpass" "unistd.h" HAVE_GETPASS)
endif ()

# TODO
if (NOT HAVE_GETPASS)
  message(FATAL_ERROR "No implementation of 'getpass' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getpass.cmake)
endif ()

