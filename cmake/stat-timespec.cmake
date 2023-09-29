
include_guard(GLOBAL)

check_c_struct_has_member("struct stat" "st_atim" "sys/types.h;sys/time.h;sys/stat.h;time.h" HAVE_STRUCT_STAT_ST_ATIM)
check_c_struct_has_member("struct stat" "st_ctim" "sys/types.h;sys/time.h;sys/stat.h;time.h" HAVE_STRUCT_STAT_ST_CTIM)
check_c_struct_has_member("struct stat" "st_mtim" "sys/types.h;sys/time.h;sys/stat.h;time.h" HAVE_STRUCT_STAT_ST_MTIM)
check_c_struct_has_member("struct stat" "st_atimespec" "sys/types.h;sys/time.h;sys/stat.h;time.h" HAVE_STRUCT_STAT_ST_ATIMESPEC)
check_c_struct_has_member("struct stat" "st_ctimespec" "sys/types.h;sys/time.h;sys/stat.h;time.h" HAVE_STRUCT_STAT_ST_CTIMESPEC)
check_c_struct_has_member("struct stat" "st_mtimespec" "sys/types.h;sys/time.h;sys/stat.h;time.h" HAVE_STRUCT_STAT_ST_MTIMESPEC)

check_c_compiles("
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>

int
main (int argc, char **argv)
{
  struct stat st;
  struct timespec tspec;
  long int nanoseconds;
  st.st_atim = tspec;
  st.st_atim.tv_nsec = nanoseconds;
  return 0;
}" HAVE_STRUCT_STAT_ST_ATIM_TIMESPEC_TV_NSEC)

check_c_compiles("
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>

int
main (int argc, char **argv)
{
  struct stat st;
  struct timespec tspec;
  long int nanoseconds;
  st.st_ctim = tspec;
  st.st_ctim.tv_nsec = nanoseconds;
  return 0;
}" HAVE_STRUCT_STAT_ST_CTIM_TIMESPEC_TV_NSEC)

check_c_compiles("
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>

int
main (int argc, char **argv)
{
  struct stat st;
  struct timespec tspec;
  long int nanoseconds;
  st.st_mtim = tspec;
  st.st_mtim.tv_nsec = nanoseconds;
  return 0;
}" HAVE_STRUCT_STAT_ST_MTIM_TIMESPEC_TV_NSEC)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/stat-timespec.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/stat-timespec.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stat-timespec.cmake)
endif ()

