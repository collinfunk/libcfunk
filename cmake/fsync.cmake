
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("fsync" "unistd.h" HAVE_FSYNC)
endif ()

set(LIBCFUNK_DECLARE_FSYNC "1" CACHE STRING "")

if (NOT HAVE_FSYNC)
  check_include_files("windows.h" HAVE_WINDOWS_H)
  if (NOT HAVE_WINDOWS_H)
    message(FATAL_ERROR "No implementation of 'fsync' for your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fsync.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fsync.cmake)
endif ()

