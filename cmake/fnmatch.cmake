
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/fnmatch-h.cmake)

if (HAVE_FNMATCH_H)
  check_symbol_exists("fnmatch" "fnmatch.h" HAVE_FNMATCH)
endif ()

set(LIBCFUNK_DECLARE_FNMATCH "1" CACHE STRING "")

if (NOT HAVE_FNMATCH OR LIBCFUNK_REPLACE_FNMATCH)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fnmatch.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fnmatch.cmake)
endif ()

