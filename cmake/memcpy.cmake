
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("memcpy" "string.h" HAVE_MEMCPY)
endif ()

set(LIBCFUNK_DECLARE_MEMCPY "1" CACHE STRING "")

if (NOT HAVE_MEMCPY OR LIBCFUNK_DECLARE_MEMCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/memcpy.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-memcpy.cmake)
endif ()

