
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/rand.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("rand" "stdlib.h" HAVE_RAND)
endif ()

set(LIBCFUNK_DECLARE_RAND "1" CACHE STRING "")

if (NOT HAVE_RAND OR LIBCFUNK_REPLACE_RAND)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/rand.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-rand.cmake)
endif ()

