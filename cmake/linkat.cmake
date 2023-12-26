
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("linkat" "unistd.h" HAVE_LINKAT)
endif ()

# TODO
if (NOT HAVE_LINKAT)
  message(FATAL_ERROR "No implementation of 'linkat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

