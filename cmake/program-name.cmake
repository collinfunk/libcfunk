
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/filename.cmake)

# GNU glibc and musl.
check_symbol_exists("program_invocation_name" "errno.h" HAVE_PROGRAM_INVOCATION_NAME)
check_symbol_exists("program_invocation_short_name" "errno.h" HAVE_PROGRAM_INVOCATION_SHORT_NAME)

# 4.4BSD
check_symbol_exists("__progname" "stdlib.h" HAVE___PROGNAME)

# NetBSD, FreeBSD, DragonFly, OpenBSD
check_symbol_exists("getprogname" "stdlib.h" HAVE_GETPROGNAME)
check_symbol_exists("setprogname" "stdlib.h" HAVE_SETPROGNAME)

# Solaris
check_symbol_exists("getexecname" "stdlib.h" HAVE_GETEXECNAME)

# Windows
check_symbol_exists("__argc" "stdlib.h" HAVE___ARGC)
check_symbol_exists("__argv" "stdlib.h" HAVE___ARGV)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/program-name.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/program-name.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-program-name.cmake)
endif ()

