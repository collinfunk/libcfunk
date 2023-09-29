include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

check_c_symbol("timespec_get" "time.h")
check_c_symbol("clock_gettime" "time.h")
check_c_symbol("gettimeofday" "sys/time.h;time.h")

set(LIBCFUNK_DECLARE_TIMESPEC_GET "1" CACHE INTERNAL "")

if (NOT HAVE_TIMESPEC_GET)
  if (NOT HAVE_CLOCK_GETTIME AND NOT HAVE_GETTIMEOFDAY)
    message(FATAL_ERROR "Could not find a replacement for `timespec_get'.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/timespec-get.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-timespec-get.cmake)
endif ()
