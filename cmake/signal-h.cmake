
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <signal.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SIGNAL_H "1" CACHE INTERNAL "")

check_include_file("signal.h" HAVE_SIGNAL_H)

# Check for types.
if (HAVE_SIGNAL_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "signal.h")
  check_type_size("sig_atomic_t" SIG_ATOMIC_T)
  check_type_size("sigset_t" SIGSET_T)
  check_type_size("struct sigevent" STRUCT_SIGEVENT)
  check_type_size("union sigval" UNION_SIGVAL)
  check_type_size("struct sigaction" STRUCT_SIGACTION)
  check_type_size("siginfo_t" SIGINFO_T)
  check_type_size("stack_t" STACK_T)
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "signal.h")
else ()
  set(HAVE_SIG_ATOMIC_T "" CACHE INTERNAL "")
  set(HAVE_SIGSET_T "" CACHE INTERNAL "")
  set(HAVE_STRUCT_SIGEVENT "" CACHE INTERNAL "")
  set(HAVE_UNION_SIGVAL "" CACHE INTERNAL "")
  set(HAVE_STRUCT_SIGACTION "" CACHE INTERNAL "")
  set(HAVE_SIGINFO_T "" CACHE INTERNAL "")
  set(HAVE_STACK_T "" CACHE INTERNAL "")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-signal-h.cmake)
endif ()

