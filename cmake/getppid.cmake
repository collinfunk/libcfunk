
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("getppid" "unistd.h" HAVE_GETPPID)
endif ()

set(LIBCFUNK_DECLARE_GETPPID "1" CACHE STRING "")

if (NOT HAVE_GETPPID OR LIBCFUNK_REPLACE_GETPPID)
  check_include_file("windows.h" HAVE_WINDOWS_H)
  if (NOT HAVE_WINDOWS_H)
    message(FATAL_ERROR "No implementation of 'getppid' for your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getppid.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getppid.cmake)
endif ()

