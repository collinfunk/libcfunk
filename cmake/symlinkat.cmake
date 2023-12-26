
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("symlinkat" "unistd.h" HAVE_SYMLINKAT)
endif ()

# TODO
if (NOT HAVE_SYMLINKAT)
  message(FATAL_ERROR "No implementation of 'symlinkat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

