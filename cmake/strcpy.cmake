
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strcpy" "string.h" HAVE_STRCPY)
endif ()

set(LIBCFUNK_DECLARE_STRCPY "1" CACHE STRING "")

if (NOT HAVE_STRCPY OR LIBCFUNK_REPLACE_STRCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strcpy.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strcpy.cmake)
endif ()
