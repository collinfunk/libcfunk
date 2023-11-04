
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strchr" "string.h" HAVE_STRCHR)
endif ()

set(LIBCFUNK_DECLARE_STRCHR "1" CACHE INTERNAL "")

if (NOT HAVE_STRCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strchr.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strchr.cmake)
endif ()

