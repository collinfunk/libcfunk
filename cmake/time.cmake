
include_guard(GLOBAL)

check_include_file("time.h" HAVE_TIME_H)

set(LIBCFUNK_GENERATE_TIME_H TRUE)

set(LIBCFUNK_DECLARE_DYSIZE 0)
set(LIBCFUNK_DECLARE_TIMESPEC_GET 0)

# Should probably use this instead?
# https://cmake.org/cmake/help/latest/module/CheckTypeSize.html
check_c_source_compiles("
#include <sys/types.h>

#include <time.h>

int
main (void)
{
  struct timespec value;

  value.tv_sec = 0;
  value.tv_nsec = 0;

  return 0;
}
" HAVE_STRUCT_TIMESPEC)

check_c_source_compiles("
#include <sys/types.h>

#include <time.h>

int
main (void)
{
  struct itimerspec value;

  value.it_interval.tv_sec = 0;
  value.it_interval.tv_nsec = 0;
  value.it_value.tv_sec = 0;
  value.it_value.tv_nsec = 0;
  return 0;
}
" HAVE_STRUCT_ITIMERSPEC)

if (HAVE_TIME_H)
else ()
  set(HAVE_TIME_H 0)
endif ()

