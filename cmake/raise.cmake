
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

check_include_file("unistd.h" HAVE_UNISTD_H)

if (HAVE_SIGNAL_H)
  check_symbol_exists("raise" "signal.h" HAVE_RAISE)
  check_symbol_exists("kill" "signal.h" HAVE_KILL)
endif ()

if (HAVE_UNISTD_H)
  check_symbol_exists("getpid" "unistd.h" HAVE_GETPID)
endif ()

set(LIBCFUNK_DECLARE_RAISE "1" CACHE STRING "")

if (NOT HAVE_RAISE)
  if (NOT HAVE_KILL OR NOT HAVE_GETPID)
    message(FATAL_ERROR "No implementation of 'raise' for your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/raise.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-raise.cmake)
endif ()

