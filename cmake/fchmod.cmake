
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("fchmod" "sys/stat.h" HAVE_FCHMOD)
endif ()

# TODO
if (NOT HAVE_FCHMOD)
  message(FATAL_ERROR "No implementation of 'fchmod' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

