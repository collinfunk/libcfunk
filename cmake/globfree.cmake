
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/glob-h.cmake)

if (HAVE_GLOB_H)
  check_symbol_exists("globfree" "glob.h" HAVE_GLOBFREE)
endif ()

if (NOT HAVE_GLOBFREE)
  message(FATAL_ERROR "No implementation of 'globfree' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

