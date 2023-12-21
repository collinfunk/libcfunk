
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/glob-h.cmake)

if (HAVE_GLOB_H)
  check_symbol_exists("glob_pattern_p" "glob.h" HAVE_GLOB_PATTERN_P)
endif ()

set(LIBCFUNK_DECLARE_GLOB_PATTERN_P "1" CACHE STRING "")

if (NOT HAVE_GLOB_PATTERN_P OR LIBCFUNK_REPLACE_GLOB_PATTERN_P)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/glob_pattern_p.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-glob_pattern_p.cmake)
endif ()

