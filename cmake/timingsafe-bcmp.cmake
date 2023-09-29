include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("timingsafe_bcmp" "string.h")

set(LIBCFUNK_DECLARE_TIMINGSAFE_BCMP "1" CACHE INTERNAL "")

if (NOT HAVE_TIMINGSAFE_BCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/timingsafe-bcmp.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-timingsafe-bcmp.cmake)
endif ()
