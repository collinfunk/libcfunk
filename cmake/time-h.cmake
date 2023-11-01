
include_guard(GLOBAL)

# Generate <time.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_TIME_H "1" CACHE INTERNAL "")

check_include_file("sys/time.h" HAVE_SYS_TIME_H)
check_include_file("time.h" HAVE_TIME_H)

if (HAVE_SYS_TIME_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/time.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
endif ()

if (HAVE_TIME_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "time.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct timespec" STRUCT_TIMESPEC)
  check_type_size("struct itimerspec" STRUCT_ITIMERSPEC)
else ()
  set(HAVE_STRUCT_TIMESPEC "" CACHE INTERNAL "")
  set(HAVE_STRUCT_ITIMERSPEC "" CACHE INTERNAL "")
endif ()

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_DYSIZE "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_TIMESPEC_GET "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_GMTIME_R "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_LOCALTIME_R "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_NANOSLEEP "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_TZSET "0" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-time-h.cmake)
endif ()

