
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/argz-h.cmake)

if (HAVE_ARGZ_H)
  check_symbol_exists("argz_stringify" "argz.h" HAVE_ARGZ_STRINGIFY)
endif ()

set(LIBCFUNK_DECLARE_ARGZ_STRINGIFY "1" CACHE STRING "")

if (NOT HAVE_ARGZ_STRINGIFY OR LIBCFUNK_REPLACE_ARGZ_STRINGIFY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/argz_stringify.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-argz_stringify.cmake)
endif ()

