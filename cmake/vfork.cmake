
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("vfork" "unistd.h" HAVE_VFORK)
endif ()

if (NOT HAVE_VFORK)
  message(FATAL_ERROR "No implementation of 'vfork' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-vfork.cmake)
endif ()

