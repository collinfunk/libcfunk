
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("getpagesize" "unistd.h" HAVE_GETPAGESIZE)
endif ()

set(LIBCFUNK_DECLARE_GETPAGESIZE "1" CACHE STRING "")

if (NOT HAVE_GETPAGESIZE OR LIBCFUNK_REPLACE_GETPAGESIZE)
  check_include_file("windows.h" HAVE_WINDOWS_H)
  if (HAVE_UNISTD_H)
    check_symbol_exists("sysconf" "unistd.h" HAVE_SYSCONF)
  endif ()
  if (NOT HAVE_WINDOWS_H AND NOT HAVE_SYSCONF AND NOT HAVE_GETPAGESIZE)
    message(FATAL_ERROR "Unsupported operating system. Could not implement 'getpagesize'.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getpagesize.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getpagesize.cmake)
endif ()

