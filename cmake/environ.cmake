
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_include_file("stdlib.h" HAVE_STDLIB_H)

# Check if 'environ' is declared in 'stdlib.h' or 'unistd.h'.
if (HAVE_UNISTD_H OR HAVE_STDLIB_H)
  set(ENVIRON_INCLUDES "")
  if (HAVE_UNISTD_H)
    list(APPEND ENVIRON_INCLUDES "unistd.h")
  endif ()
  if (HAVE_STDLIB_H)
    list(APPEND ENVIRON_INCLUDES "stdlib.h")
  endif ()
  check_symbol_exists("environ" "${ENVIRON_INCLUDES}" HAVE_ENVIRON)
  unset(ENVIRON_INCLUDES)
endif ()

# Some versions of MacOS require using _NSGetEnviron ().
if (NOT HAVE_ENVIRON)
  check_include_file("crt_externs.h" HAVE_CRT_EXTERNS_H)
  check_symbol_exists("_NSGetEnviron" "crt_externs.h" HAVE__NSGETENVIRON)
endif ()

set(LIBCFUNK_DECLARE_ENVIRON "1" CACHE STRING "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-environ.cmake)
endif ()

