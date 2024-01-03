
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("lchmod" "sys/stat.h" HAVE_LCHMOD)
endif ()

# TODO
if (NOT HAVE_LCHMOD)
  message(FATAL_ERROR "No implementation of 'lchmod' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()
