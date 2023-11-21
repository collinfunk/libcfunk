
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strstr" "string.h" HAVE_STRSTR)
endif ()

set(LIBCFUNK_DECLARE_STRSTR "1" CACHE STRING "")

if (NOT HAVE_STRSTR OR LIBCFUNK_REPLACE_STRSTR)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strncmp.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strstr.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strstr.cmake)
endif ()

