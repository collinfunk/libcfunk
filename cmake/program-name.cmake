
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/filename.cmake)

check_c_system_headers("errno.h")

# GNU glibc and musl.
check_c_symbol("program_invocation_name" "errno.h")
check_c_symbol("program_invocation_short_name" "errno.h")

# 4.4BSD
check_c_symbol("__progname" "stdlib.h")

# NetBSD, FreeBSD, DragonFly, OpenBSD
check_c_symbol("getprogname" "stdlib.h")
check_c_symbol("setprogname" "stdlib.h")

# Solaris
check_c_symbol("getexecname" "stdlib.h")

# Windows
check_c_symbol("__argc" "stdlib.h")
check_c_symbol("__argv" "stdlib.h")

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/program-name.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/program-name.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-program-name.cmake)
endif ()

