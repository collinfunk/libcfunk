
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strrchr" "string.h" HAVE_STRRCHR)
endif ()

set(LIBCFUNK_DECLARE_STRRCHR "1" CACHE STRING "")

if (NOT HAVE_STRRCHR OR LIBCFUNK_REPLACE_STRRCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strrchr.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strrchr.cmake)
endif ()

