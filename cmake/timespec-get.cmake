
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/time.cmake)

check_symbol_exists(timespec_get "time.h" HAVE_TIMESPEC_GET)
check_symbol_exists(clock_gettime "time.h" HAVE_CLOCK_GETTIME)

# This probably belongs in a different file.
# Marked obsolete POSIX Issue 7.
# clock_gettime(2) should be used instead.
check_symbol_exists(gettimeofday "sys/time.h" HAVE_GETTIMEOFDAY)

set(LIBCFUNK_DECLARE_TIMESPEC_GET 1)

if (NOT HAVE_TIMESPEC_GET)
  set(HAVE_TIMESPEC_GET 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/timespec-get.c
  )
endif ()

if (NOT HAVE_CLOCK_GETTIME)
  set(HAVE_CLOCK_GETTIME 0)
endif ()

if (NOT HAVE_GETTIMEOFDAY)
  set(HAVE_GETTIMEOFDAY 0)
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-timespec-get.cmake)
endif ()
