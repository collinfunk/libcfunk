
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("fchmodat" "sys/stat.h" HAVE_FCHMODAT)
endif ()

# TODO
if (NOT HAVE_FCHMODAT)
  message(FATAL_ERROR "No implementation of 'fchmodat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

