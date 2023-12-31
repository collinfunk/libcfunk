
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
  find_file(PTHREAD_H_PATH NAMES "pthread.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})

  # Check for pthreads in libc or with the '-pthread' compiler flag.
  set(THREADS_PREFER_PTHREAD_FLAG ON)
  find_package(Threads REQUIRED)
  unset(THREADS_HAVE_PTHREAD_ARG)

  # Add the library.
  target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC Threads::Threads)
  list(APPEND CMAKE_REQUIRED_LIBRARIES Threads::Threads)

  # Add the header.
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "pthread.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

  # Check for types.
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

