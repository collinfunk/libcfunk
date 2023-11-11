
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("getlogin_r" "unistd.h" HAVE_GETLOGIN_R)
endif ()

set(LIBCFUNK_DECLARE_GETLOGIN_R "1" CACHE STRING "")

if (NOT HAVE_GETLOGIN_R)
  check_include_file("windows.h" HAVE_WINDOWS_H)
  if (NOT HAVE_WINDOWS_H)
    message(FATAL_ERROR "No implemented replacement for getlogin_r(3).")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getlogin_r.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getlogin_r.cmake)
endif ()
