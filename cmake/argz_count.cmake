
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/argz-h.cmake)

if (HAVE_ARGZ_H)
  check_symbol_exists("argz_count" "argz.h" HAVE_ARGZ_COUNT)
endif ()

set(LIBCFUNK_DECLARE_ARGZ_COUNT "1" CACHE STRING "")

if (NOT HAVE_ARGZ_COUNT OR LIBCFUNK_REPLACE_ARGZ_COUNT)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/argz_count.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-argz_count.cmake)
endif ()

