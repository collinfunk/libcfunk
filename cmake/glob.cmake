
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/glob-h.cmake)

if (HAVE_GLOB_H)
  check_symbol_exists("glob" "glob.h" HAVE_GLOB)
endif ()

if (NOT HAVE_GLOB)
  message(FATAL_ERROR "No implementation of 'glob' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

