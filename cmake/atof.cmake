
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("atof" "stdlib.h" HAVE_ATOF)
endif ()

set(LIBCFUNK_DECLARE_ATOF "1" CACHE STRING "")

if (NOT HAVE_ATOF OR LIBCFUNK_REPLACE_ATOF)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strtod.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/atof.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-atof.cmake)
endif ()

