
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("faccessat" "unistd.h" HAVE_FACCESSAT)
endif ()

# TODO
if (NOT HAVE_FACCESSAT)
  message(FATAL_ERROR "No implementation of 'faccessat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

