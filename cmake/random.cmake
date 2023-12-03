
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/rand.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("random" "stdlib.h" HAVE_RANDOM)
endif ()

set(LIBCFUNK_DECLARE_RANDOM "1" CACHE STRING "")

if (NOT HAVE_RANDOM OR LIBCFUNK_REPLACE_RANDOM)
  include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/random.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-random.cmake)
endif ()

