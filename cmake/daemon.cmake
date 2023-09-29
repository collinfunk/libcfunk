
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/_Exit.cmake)

check_c_symbol("daemon" "unistd.h")
check_c_symbol("fork" "unistd.h")
check_c_symbol("setsid" "unistd.h")
check_c_symbol("dup2" "unistd.h")

set(LIBCFUNK_DECLARE_DAEMON "1" CACHE INTERNAL "")

if (NOT HAVE_DAEMON)
  # This is pretty much just a check to see if the host is Windows.
  # However, just use these functions since we need them anyways and there
  # might be a weird system missing them.
  if (NOT HAVE_FORK OR NOT HAVE_SETSID OR NOT HAVE_DUP2)
    message(FATAL_ERROR "daemon(3) requires a system with fork(2), dup2(2), \
and setsid(2).")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/daemon.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-daemon.cmake)
endif ()
