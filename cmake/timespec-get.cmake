
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/time.cmake)

libcfunk_check_symbol_exists(timespec_get "time.h" HAVE_TIMESPEC_GET)
libcfunk_check_symbol_exists(clock_gettime "time.h" HAVE_CLOCK_GETTIME)

# This probably belongs in a different file.
# Marked obsolete POSIX Issue 7.
# clock_gettime(2) should be used instead.
libcfunk_check_symbol_exists(gettimeofday "sys/time.h" HAVE_GETTIMEOFDAY)

set(LIBCFUNK_DECLARE_TIMESPEC_GET 1)

if (NOT HAVE_TIMESPEC_GET)
  libcfunk_add_sources("timespec-get.c")
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-timespec-get.cmake)
endif ()
