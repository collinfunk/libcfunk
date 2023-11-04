
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("gmtime_r" "time.h" HAVE_GMTIME_R)
endif ()

set(LIBCFUNK_DECLARE_GMTIME_R "1" CACHE INTERNAL "")

if (NOT HAVE_GMTIME_R)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/gmtime-r.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-gmtime-r.cmake)
endif ()

