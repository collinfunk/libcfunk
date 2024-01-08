
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)

# Generate <time.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_TIME_H "1" CACHE STRING "")

check_include_file("sys/time.h" HAVE_SYS_TIME_H)
check_include_file("time.h" HAVE_TIME_H)

if (HAVE_SYS_TIME_H OR HAVE_TIME_H)
  if (HAVE_SYS_TIME_H)
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/time.h")
  endif ()
  if (HAVE_TIME_H)
    find_file(TIME_H_PATH NAMES "time.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "time.h")
  endif ()
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct timespec" STRUCT_TIMESPEC)
  check_type_size("struct itimerspec" STRUCT_ITIMERSPEC)
  check_type_size("struct tm" STRUCT_TM)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-time-h.cmake)
endif ()

