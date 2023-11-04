
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("memset_explicit" "string.h" HAVE_MEMSET_EXPLICIT)
endif ()

set(LIBCFUNK_DECLARE_MEMSET_EXPLICIT "1" CACHE STRING "")

if (NOT HAVE_MEMSET_EXPLICIT)
  check_symbol_exists("memset_s" "string.h" HAVE_MEMSET_S)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/memset-explicit.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-memset-explicit.cmake)
endif ()
