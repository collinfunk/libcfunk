include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("timespec_get" "time.h" HAVE_TIMESPEC_GET)
else ()
  set(HAVE_TIMESPEC_GET "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_TIMESPEC_GET "1" CACHE INTERNAL "")

if (NOT HAVE_TIMESPEC_GET)
  check_symbol_exists("clock_gettime" "time.h" HAVE_CLOCK_GETTIME)
  check_symbol_exists("gettimeofday" "sys/time.h;time.h" HAVE_GETTIMEOFDAY)
  if (NOT HAVE_CLOCK_GETTIME AND NOT HAVE_GETTIMEOFDAY)
    message(FATAL_ERROR "Could not find a replacement for `timespec_get'.")
  endif ()
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/timespec-get.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-timespec-get.cmake)
endif ()
