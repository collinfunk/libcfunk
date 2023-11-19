
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strtok_r" "string.h" HAVE_STRTOK_R)
endif ()

set(LIBCFUNK_DECLARE_STRTOK_R "1" CACHE STRING "")

if (NOT HAVE_STRTOK_R OR LIBCFUNK_REPLACE_STRTOK_R)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strcspn.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strspn.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtok_r.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strtok_r.cmake)
endif ()

