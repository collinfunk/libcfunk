
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <signal.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SIGNAL_H "1" CACHE INTERNAL "")

check_include_file("pthread.h" HAVE_PTHREAD_H)
check_include_file("signal.h" HAVE_SIGNAL_H)

if (HAVE_PTHREAD_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "pthread.h")
endif ()

if (HAVE_SIGNAL_H)
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

set(LIBCFUNK_DECLARE_RAISE "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_SIG2STR "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_SIGADDSET "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_SIGDELSET "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_SIGEMPTYSET "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_SIGFILLSET "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_SIGISMEMBER "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_SIGPROCMASK "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STR2SIG "0" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-signal-h.cmake)
endif ()

