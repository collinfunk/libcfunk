
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("memset_explicit" "string.h")
check_c_symbol("memset_s" "string.h")

set(LIBCFUNK_DECLARE_MEMSET_EXPLICIT "1" CACHE INTERNAL "")

if (NOT HAVE_MEMSET_EXPLICIT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/memset-explicit.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-memset-explicit.cmake)
endif ()
