
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("readlinkat" "unistd.h" HAVE_READLINKAT)
endif ()

# TODO
if (NOT HAVE_READLINKAT)
  message(FATAL_ERROR "No implementation of 'readlinkat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

