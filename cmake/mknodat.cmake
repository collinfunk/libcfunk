
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("mknodat" "sys/stat.h" HAVE_MKNODAT)
endif ()

# TODO
if (NOT HAVE_MKNODAT)
  message(FATAL_ERROR "No implementation of 'mknodat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

