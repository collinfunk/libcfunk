
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/pthread-h.cmake)

# Generate <threads.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_THREADS_H "1" CACHE STRING "")

check_include_file("threads.h" HAVE_THREADS_H)

if (HAVE_THREADS_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "threads.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

  # FreeBSD has these in libstdthreads.
  find_library(STDTHREADS_LIBRARY "stdthreads")
  if (STDTHREADS_LIBRARY)
    target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "${STDTHREADS_LIBRARY}")
    list(APPEND CMAKE_REQUIRED_LIBRARIES "${STDTHREADS_LIBRARY}")
  endif ()

  # Type checks
  check_type_size("cnd_t" CND_T)
  check_type_size("thrd_t" THRD_T)
  check_type_size("tss_t" TSS_T)
  check_type_size("mtx_t" MTX_T)
  check_type_size("tss_dtor_t" TSS_DTOR_T)
  check_type_size("thrd_start_t" THRD_START_T)
  check_type_size("once_flag" ONCE_FLAG)
endif ()

# Test if the compiler supports the 'thread_local' keyword defined by C23.
check_c_source_compiles("
thread_local int value;
int
main (void)
{
  value = 0;
  return value;
}" HAVE_C23_THREAD_LOCAL)

# Test if the compiler supports the '_Thread_local' keyword defined by C11.
check_c_source_compiles("
_Thread_local int value;
int
main (void)
{
  value = 0;
  return value;
}" HAVE_C11__THREAD_LOCAL)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-threads-h.cmake)
endif ()

