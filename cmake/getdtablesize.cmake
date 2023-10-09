
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("getdtablesize" "unistd.h" HAVE_GETDTABLESIZE)
  check_symbol_exists("sysconf" "unistd.h" HAVE_SYSCONF)
else ()
  set(HAVE_GETDTABLESIZE "" CACHE INTERNAL "")
  set(HAVE_SYSCONF "" CACHE INTERNAL "")
endif ()

check_include_file("sys/resource.h" HAVE_SYS_RESOURCE_H)
check_include_file("stdio.h" HAVE_STDIO_H)

if (HAVE_SYS_RESOURCE_H)
  check_symbol_exists("getrlimit" "sys/resource.h" HAVE_GETRLIMIT)
else ()
  set(HAVE_GETRLIMIT "" CACHE INTERNAL "")
endif ()

if (HAVE_STDIO_H)
  check_symbol_exists("_getmaxstdio" "stdio.h" HAVE__GETMAXSTDIO)
else ()
  set(HAVE__GETMAXSTDIO "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_GETDTABLESIZE "1" CACHE INTERNAL "")

if (NOT HAVE_GETDTABLESIZE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getdtablesize.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getdtablesize.cmake)
endif ()