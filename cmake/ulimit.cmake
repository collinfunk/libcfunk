
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ulimit-h.cmake)

if (HAVE_ULIMIT_H)
  check_symbol_exists("ulimit" "ulimit.h" HAVE_ULIMIT)
endif ()

set(LIBCFUNK_DECLARE_ULIMIT "1" CACHE STRING "")

if (NOT HAVE_ULIMIT OR LIBCFUNK_REPLACE_ULIMIT)
  include($CACHE{LIBCFUNK_MODULE_DIR}/stdarg-h.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)
  check_include_file("sys/resource.h" HAVE_SYS_RESOURCE_H)
  if (HAVE_SYS_RESOURCE_H)
    check_symbol_exists("getrlimit" "sys/resource.h" HAVE_GETRLIMIT)
    check_symbol_exists("setrlimit" "sys/resource.h" HAVE_SETRLIMIT)
  endif ()
  if (NOT HAVE_SYS_RESOURCE_H OR NOT HAVE_GETRLIMIT OR NOT HAVE_SETRLIMIT)
    message(FATAL_ERROR "No implementation of 'ulimit' for your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ulimit.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ulimit.cmake)
endif ()

