
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

if (HAVE_FCNTL_H)
  check_symbol_exists("openat" "fcntl.h" HAVE_OPENAT)
endif ()

# TODO
if (NOT HAVE_OPENAT)
  message(FATAL_ERROR "No implementation of 'openat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

