
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("random_r" "stdlib.h" HAVE_RANDOM_R)
endif ()

set(LIBCFUNK_DECLARE_RANDOM_R "1" CACHE STRING "")

if (NOT HAVE_RANDOM_R OR LIBCFUNK_REPLACE_RANDOM_R)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/random_r.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

