
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("utimensat" "sys/stat.h" HAVE_UTIMENSAT)
endif ()

# TODO
if (NOT HAVE_UTIMENSAT)
  message(FATAL_ERROR "No implementation of 'utimensat' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

