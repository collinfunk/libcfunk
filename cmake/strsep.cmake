
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strsep" "string.h" HAVE_STRSEP)
endif ()

set(LIBCFUNK_DECLARE_STRSEP "1" CACHE STRING "")

if (NOT HAVE_STRSEP OR LIBCFUNK_REPLACE_STRSEP)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strchr.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strpbrk.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strsep.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strsep.cmake)
endif ()

