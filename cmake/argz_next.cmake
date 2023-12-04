
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/argz-h.cmake)

if (HAVE_ARGZ_H)
  check_symbol_exists("argz_next" "argz.h" HAVE_ARGZ_NEXT)
endif ()

set(LIBCFUNK_DECLARE_ARGZ_NEXT "1" CACHE STRING "")

if (NOT HAVE_ARGZ_NEXT OR LIBCFUNK_REPLACE_ARGZ_NEXT)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strchr.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/argz_next.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-argz_next.cmake)
endif ()

