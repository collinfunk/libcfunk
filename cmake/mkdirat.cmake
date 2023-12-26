
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("mkdirat" "sys/stat.h" HAVE_MKDIRAT)
endif ()

# TODO
if (NOT HAVE_MKDIRAT)
  message(FATAL_ERROR "No implementation of 'mkdirat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

