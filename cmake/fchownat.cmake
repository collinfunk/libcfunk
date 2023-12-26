
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("fchownat" "unistd.h" HAVE_FCHOWNAT)
endif ()

# TODO
if (NOT HAVE_FCHOWNAT)
  message(FATAL_ERROR "No implementation of 'fchownat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

