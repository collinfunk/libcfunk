
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("futimens" "sys/stat.h" HAVE_FUTIMENS)
endif ()

# TODO
if (NOT HAVE_FUTIMENS)
  message(FATAL_ERROR "No implementation of 'futimens' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

