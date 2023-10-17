
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("tzset" "time.h" HAVE_TZSET)
  check_symbol_exists("_tzset" "time.h" HAVE__TZSET)
else ()
  set(HAVE_TZSET "" CACHE INTERNAL "")
  set(HAVE__TZSET "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_TZSET "1" CACHE INTERNAL "")

if (NOT HAVE_TZSET)
  if (NOT HAVE__TZSET)
    message(FATAL_ERROR "No implementation of 'tzset' for your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/tzset.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-tzset.cmake)
endif ()

