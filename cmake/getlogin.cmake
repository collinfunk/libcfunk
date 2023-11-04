
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("getlogin" "unistd.h" HAVE_GETLOGIN)
endif ()

set(LIBCFUNK_DECLARE_GETLOGIN "1" CACHE INTERNAL "")

if (NOT HAVE_GETLOGIN)
  check_include_file("windows.h" HAVE_WINDOWS_H)
  if (NOT HAVE_WINDOWS_H)
    message(FATAL_ERROR "No implemented replacement for getlogin(3).")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getlogin.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getlogin.cmake)
endif ()
