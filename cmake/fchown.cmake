
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("fchown" "unistd.h" HAVE_FCHOWN)
endif ()

# TODO
if (NOT HAVE_FCHOWN)
  message(FATAL_ERROR "No implementation of 'fchown' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

