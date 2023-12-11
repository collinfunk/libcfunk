
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("getprogname" "stdlib.h" HAVE_GETPROGNAME)
endif ()

set(LIBCFUNK_DECLARE_GETPROGNAME "1" CACHE STRING "")

if (NOT HAVE_GETPROGNAME OR LIBCFUNK_REPLACE_GETPROGNAME)
  include($CACHE{LIBCFUNK_MODULE_DIR}/filename.cmake)
  check_include_file("errno.h" HAVE_ERRNO_H)
  if (HAVE_ERRNO_H)
    check_symbol_exists("program_invocation_short_name" "errno.h" HAVE_PROGRAM_INVOCATION_SHORT_NAME)
    check_symbol_exists("program_invocation_name" "errno.h" HAVE_PROGRAM_INVOCATION_NAME)
  endif ()
  if (HAVE_STDLIB_H)
    check_symbol_exists("__argv" "stdlib.h" HAVE___ARGV)
    check_symbol_exists("__argc" "stdlib.h" HAVE___ARGC)
    check_symbol_exists("getexecname" "stdlib.h" HAVE_GETEXECNAME)
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getprogname.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getprogname.cmake)
endif ()

