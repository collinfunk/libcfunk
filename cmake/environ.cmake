
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

# Check if stdlib.h or unistd.h has `environ' declared already.
# This is declared in `unistd.h' to match glibc.
check_c_symbol("environ" "stdlib.h;unistd.h")

# Some versions of MacOS require using _NSGetEnviron ().
check_c_system_headers("crt_externs.h")
check_c_symbol("_NSGetEnviron" "crt_externs.h")

set(LIBCFUNK_DECLARE_ENVIRON "1" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-environ.cmake)
endif ()
