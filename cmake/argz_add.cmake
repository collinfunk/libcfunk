
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/argz-h.cmake)

if (HAVE_ARGZ_H)
  check_symbol_exists("argz_add" "argz.h" HAVE_ARGZ_ADD)
endif ()

set(LIBCFUNK_DECLARE_ARGZ_ADD "1" CACHE STRING "")

if (NOT HAVE_ARGZ_ADD OR LIBCFUNK_REPLACE_ARGZ_ADD)
  include($CACHE{LIBCFUNK_MODULE_DIR}/argz_append.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/argz_add.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-argz_add.cmake)
endif ()

