
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("link" "unistd.h" HAVE_LINK)
endif ()

# TODO
if (NOT HAVE_LINK)
  message(FATAL_ERROR "No implementation of 'link' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-link.cmake)
endif ()

