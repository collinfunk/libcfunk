
include_guard(GLOBAL)

# Generate <time.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_TIME_H "1" CACHE STRING "")

check_include_file("sys/time.h" HAVE_SYS_TIME_H)
check_include_file("time.h" HAVE_TIME_H)

if (HAVE_SYS_TIME_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/time.h")
endif ()

if (HAVE_TIME_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "time.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("struct timespec" STRUCT_TIMESPEC)
check_type_size("struct itimerspec" STRUCT_ITIMERSPEC)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-time-h.cmake)
endif ()

