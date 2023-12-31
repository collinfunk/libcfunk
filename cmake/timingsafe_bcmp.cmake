
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("timingsafe_bcmp" "string.h" HAVE_TIMINGSAFE_BCMP)
endif ()

set(LIBCFUNK_DECLARE_TIMINGSAFE_BCMP "1" CACHE STRING "")

if (NOT HAVE_TIMINGSAFE_BCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/timingsafe_bcmp.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-timingsafe_bcmp.cmake)
endif ()

