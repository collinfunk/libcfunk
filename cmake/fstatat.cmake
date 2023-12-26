
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("fstatat" "sys/stat.h" HAVE_FSTATAT)
endif ()

# TODO
if (NOT HAVE_FSTATAT)
  message(FATAL_ERROR "No implementation of 'fstatat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

