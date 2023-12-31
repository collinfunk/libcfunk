
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("getdtablesize" "unistd.h" HAVE_GETDTABLESIZE)
endif ()

set(LIBCFUNK_DECLARE_GETDTABLESIZE "1" CACHE STRING "")

if (NOT HAVE_GETDTABLESIZE OR LIBCFUNK_REPLACE_GETDTABLESIZE)
  check_include_file("sys/resource.h" HAVE_SYS_RESOURCE_H)
  check_include_file("windows.h" HAVE_WINDOWS_H)
  if (HAVE_UNISTD_H)
    check_symbol_exists("sysconf" "unistd.h" HAVE_SYSCONF)
  endif ()
  if (HAVE_SYS_RESOURCE_H)
    check_symbol_exists("getrlimit" "sys/resource.h" HAVE_GETRLIMIT)
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getdtablesize.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getdtablesize.cmake)
endif ()
