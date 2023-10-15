
include_guard(GLOBAL)

check_include_file("sys/types.h" HAVE_SYS_TYPES_H)
check_include_file("sys/time.h" HAVE_SYS_TIME_H)
check_include_file("sys/stat.h" HAVE_SYS_STAT_H)
check_include_file("time.h" HAVE_TIME_H)

set(STAT_TIMESPEC_INCLUDES "")

if (HAVE_SYS_TYPES_H)
  list(APPEND STAT_TIMESPEC_INCLUDES "sys/types.h")
endif ()

if (HAVE_SYS_TIME_H)
  list(APPEND STAT_TIMESPEC_INCLUDES "sys/time.h")
endif ()

if (HAVE_SYS_STAT_H)
  list(APPEND STAT_TIMESPEC_INCLUDES "sys/stat.h")
endif ()

if (HAVE_TIME_H)
  list(APPEND STAT_TIMESPEC_INCLUDES "time.h")
endif ()

check_struct_has_member("struct stat" "st_atim" "${STAT_TIMESPEC_INCLUDES}" HAVE_STRUCT_STAT_ST_ATIM)
check_struct_has_member("struct stat" "st_ctim" "${STAT_TIMESPEC_INCLUDES}" HAVE_STRUCT_STAT_ST_CTIM)
check_struct_has_member("struct stat" "st_mtim" "${STAT_TIMESPEC_INCLUDES}" HAVE_STRUCT_STAT_ST_MTIM)
check_struct_has_member("struct stat" "st_atimespec" "${STAT_TIMESPEC_INCLUDES}" HAVE_STRUCT_STAT_ST_ATIMESPEC)
check_struct_has_member("struct stat" "st_ctimespec" "${STAT_TIMESPEC_INCLUDES}" HAVE_STRUCT_STAT_ST_CTIMESPEC)
check_struct_has_member("struct stat" "st_mtimespec" "${STAT_TIMESPEC_INCLUDES}" HAVE_STRUCT_STAT_ST_MTIMESPEC)

if (HAVE_STRUCT_STAT_ST_ATIM)
  check_struct_has_member("struct stat" "st_atim.tv_nsec" "${STAT_TIMESPEC_INCLUDES}" HAVE_STRUCT_STAT_ST_ATIM_TIMESPEC_TV_NSEC)
endif ()

if (HAVE_STRUCT_STAT_ST_CTIM)
  check_struct_has_member("struct stat" "st_ctim.tv_nsec" "${STAT_TIMESPEC_INCLUDES}" HAVE_STRUCT_STAT_ST_CTIM_TIMESPEC_TV_NSEC)
endif ()

if (HAVE_STRUCT_STAT_ST_MTIM)
  check_struct_has_member("struct stat" "st_mtim.tv_nsec" "${STAT_TIMESPEC_INCLUDES}" HAVE_STRUCT_STAT_ST_MTIM_TIMESPEC_TV_NSEC)
endif ()

unset(STAT_TIMESPEC_INCLUDES)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/stat-timespec.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/stat-timespec.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stat-timespec.cmake)
endif ()

