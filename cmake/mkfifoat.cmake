
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("mkfifoat" "sys/stat.h" HAVE_MKFIFOAT)
endif ()

# TODO
if (NOT HAVE_MKFIFOAT)
  message(FATAL_ERROR "No implementation of 'mkfifoat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

