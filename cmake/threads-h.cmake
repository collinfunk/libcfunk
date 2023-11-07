
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/pthread-h.cmake)

# Generate <threads.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_THREADS_H "1" CACHE STRING "")

check_include_file("threads.h" HAVE_THREADS_H)

if (HAVE_THREADS_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "threads.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("cnd_t" CND_T)
  check_type_size("thrd_t" THRD_T)
  check_type_size("tss_t" TSS_T)
  check_type_size("mtx_t" MTX_T)
  check_type_size("tss_dtor_t" TSS_DTOR_T)
  check_type_size("thrd_start_t" THRD_START_T)
  check_type_size("once_flag" ONCE_FLAG)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-threads-h.cmake)
endif ()

