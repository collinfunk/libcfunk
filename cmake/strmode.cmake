include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

check_c_symbol("strmode" "string.h")

set(LIBCFUNK_DECLARE_STRMODE "1" CACHE INTERNAL "")

if (NOT HAVE_STRMODE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strmode.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strmode.cmake)
endif ()
