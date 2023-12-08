
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/argz-h.cmake)

if (HAVE_ARGZ_H)
  check_symbol_exists("argz_create" "argz.h" HAVE_ARGZ_CREATE)
endif ()

set(LIBCFUNK_DECLARE_ARGZ_CREATE "1" CACHE STRING "")

if (NOT HAVE_ARGZ_CREATE OR LIBCFUNK_REPLACE_ARGZ_CREATE)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/stpcpy.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/argz_create.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-argz_create.cmake)
endif ()

