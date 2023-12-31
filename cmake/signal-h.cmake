
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <signal.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SIGNAL_H "1" CACHE STRING "")

check_include_file("pthread.h" HAVE_PTHREAD_H)
check_include_file("signal.h" HAVE_SIGNAL_H)

if (HAVE_PTHREAD_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "pthread.h")
endif ()

if (HAVE_SIGNAL_H)
  find_file(SIGNAL_H_PATH NAMES "signal.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "signal.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("sig_atomic_t" SIG_ATOMIC_T)
check_type_size("sigset_t" SIGSET_T)
check_type_size("struct sigevent" STRUCT_SIGEVENT)
check_type_size("union sigval" UNION_SIGVAL)
check_type_size("struct sigaction" STRUCT_SIGACTION)
check_type_size("siginfo_t" SIGINFO_T)
check_type_size("stack_t" STACK_T)
check_type_size("sighandler_t" SIGHANDLER_T)
check_type_size("sig_t" SIG_T)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-signal-h.cmake)
endif ()

