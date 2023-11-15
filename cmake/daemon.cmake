
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/_Exit.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/null-device.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/dup2.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("daemon" "unistd.h" HAVE_DAEMON)
endif ()

set(LIBCFUNK_DECLARE_DAEMON "1" CACHE STRING "")

if (NOT HAVE_DAEMON)
  if (HAVE_UNISTD_H)
    check_symbol_exists("fork" "unistd.h" HAVE_FORK)
    check_symbol_exists("setsid" "unistd.h" HAVE_SETSID)
  endif ()
  # This is pretty much just a check to see if the host is Windows.
  # However, just use these functions since we need them anyways and there
  # might be a weird system missing them.
  if (NOT HAVE_FORK OR NOT HAVE_SETSID)
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
