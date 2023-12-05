
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/argz-h.cmake)

if (HAVE_ARGZ_H)
  check_symbol_exists("argz_append" "argz.h" HAVE_ARGZ_APPEND)
endif ()

set(LIBCFUNK_DECLARE_ARGZ_APPEND "1" CACHE STRING "")

if (NOT HAVE_ARGZ_APPEND OR LIBCFUNK_REPLACE_ARGZ_APPEND)
  include($CACHE{LIBCFUNK_MODULE_DIR}/memcpy.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/argz_append.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-argz_append.cmake)
endif ()

