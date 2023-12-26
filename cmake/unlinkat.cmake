
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("unlinkat" "unistd.h" HAVE_UNLINKAT)
endif ()

# TODO
if (NOT HAVE_UNLINKAT)
  message(FATAL_ERROR "No implementation of 'unlinkat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

