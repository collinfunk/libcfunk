
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

# Check if stdlib.h or unistd.h has `environ' declared already.
# This is declared in `unistd.h' to match glibc.
check_symbol_exists("environ" "stdlib.h;unistd.h" HAVE_ENVIRON)

# Some versions of MacOS require using _NSGetEnviron ().
check_include_file("crt_externs.h" HAVE_CRT_EXTERNS_H)
check_symbol_exists("_NSGetEnviron" "crt_externs.h" HAVE__NSGETENVIRON)

set(LIBCFUNK_DECLARE_ENVIRON "1" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-environ.cmake)
endif ()
