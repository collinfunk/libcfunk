
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/filename.cmake)

# glibc
libcfunk_check_symbol_exists(program_invocation_name "errno.h" HAVE_PROGRAM_INVOCATION_NAME)
libcfunk_check_symbol_exists(program_invocation_short_name "errno.h" HAVE_PROGRAM_INVOCATION_SHORT_NAME)

# BSD
libcfunk_check_symbol_exists(getprogname "stdlib.h" HAVE_GETPROGNAME)
libcfunk_check_symbol_exists(setprogname "stdlib.h" HAVE_SETPROGNAME)

# Solaris
libcfunk_check_symbol_exists(getexecname "stdlib.h" HAVE_GETEXECNAME)

# Windows
libcfunk_check_symbol_exists(__argc "stdlib.h" HAVE___ARGC)
libcfunk_check_symbol_exists(__argv "stdlib.h" HAVE___ARGV)

# I don't think the BSD's define this in a header so we have to check
# ourselves.
check_c_source_compiles("
extern char *__progname;

int
main (void)
{
  __progname = NULL;
}"
HAVE__PROG_NAME)

if (NOT HAVE__PROG_NAME)
  set(HAVE__PROG_NAME 0)
endif ()

libcfunk_add_sources("program-name.h;program-name.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-program-name.cmake)
endif ()
