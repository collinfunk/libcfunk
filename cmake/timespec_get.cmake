
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/gettimeofday.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("timespec_get" "time.h" HAVE_TIMESPEC_GET)
  check_symbol_exists("clock_gettime" "time.h" HAVE_CLOCK_GETTIME)
  if (NOT HAVE_CLOCK_GETTIME)
    unset(HAVE_CLOCK_GETTIME CACHE)
    check_library_exists("rt" "clock_gettime" "" HAVE_CLOCK_GETTIME)
    if (HAVE_CLOCK_GETTIME)
      target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "rt")
      list(APPEND CMAKE_REQUIRED_LIBRARIES "rt")
    endif ()
  endif ()
endif ()

set(LIBCFUNK_DECLARE_TIMESPEC_GET "1" CACHE STRING "")

if (NOT HAVE_TIMESPEC_GET)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/timespec_get.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-timespec_get.cmake)
endif ()

