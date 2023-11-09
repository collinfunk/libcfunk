
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sched-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

# Generate <pthread.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_PTHREAD_H "1" CACHE STRING "")

check_include_file("pthread.h" HAVE_PTHREAD_H)
check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("signal.h" HAVE_SIGNAL_H)

if (HAVE_SIGNAL_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "signal.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
endif ()

if (HAVE_PTHREAD_H)
  # Find the pthread library to link to.
  find_library(PTHREAD_LIBRARY "pthread" REQUIRED)
  target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "${PTHREAD_LIBRARY}")
  list(APPEND CMAKE_REQUIRED_LIBRARIES "${PTHREAD_LIBRARY}")

  # Check for types.
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "pthread.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("pthread_attr_t" PTHREAD_ATTR_T)
  check_type_size("pthread_barrier_t" PTHREAD_BARRIER_T)
  check_type_size("pthread_barrierattr_t" PTHREAD_BARRIERATTR_T)
  check_type_size("pthread_cond_t" PTHREAD_COND_T)
  check_type_size("pthread_condattr_t" PTHREAD_CONDATTR_T)
  check_type_size("pthread_key_t" PTHREAD_KEY_T)
  check_type_size("pthread_mutex_t" PTHREAD_MUTEX_T)
  check_type_size("pthread_mutexattr_t" PTHREAD_MUTEXATTR_T)
  check_type_size("pthread_once_t" PTHREAD_ONCE_T)
  check_type_size("pthread_rwlock_t" PTHREAD_RWLOCK_T)
  check_type_size("pthread_rwlockattr_t" PTHREAD_RWLOCKATTR_T)
  check_type_size("pthread_spinlock_t" PTHREAD_SPINLOCK_T)
  check_type_size("pthread_t" PTHREAD_T)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-pthread-h.cmake)
endif ()

