
include_guard(GLOBAL)

# glibc
check_symbol_exists(program_invocation_name "errno.h" HAVE_PROGRAM_INVOCATION_NAME)
check_symbol_exists(program_invocation_short_name "errno.h" HAVE_PROGRAM_INVOCATION_SHORT_NAME)

# BSD
check_symbol_exists(getprogname "stdlib.h" HAVE_GETPROGNAME)
check_symbol_exists(setprogname "stdlib.h" HAVE_SETPROGNAME)

# Solaris
check_symbol_exists(getexecname "stdlib.h" HAVE_GETEXECNAME)

# Windows
check_symbol_exists(__argc "stdlib.h" HAVE___ARGC)
check_symbol_exists(__argv "stdlib.h" HAVE___ARGV)

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

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/program-name.h
  ${LIBCFUNK_SOURCE_DIR}/program-name.c
)

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-program-name.cmake)
endif ()

if (NOT HAVE_PROGRAM_INVOCATION_NAME)
  set(HAVE_PROGRAM_INVOCATION_NAME 0)
endif ()

if (NOT HAVE_PROGRAM_INVOCATION_SHORT_NAME)
  set(HAVE_PROGRAM_INVOCATION_SHORT_NAME 0)
endif ()

if (NOT HAVE_GETPROGNAME)
  set(HAVE_GETPROGNAME 0)
endif ()

if (NOT HAVE_SETPROGNAME)
  set(HAVE_SETPROGNAME 0)
endif ()

if (NOT HAVE__PROG_NAME)
  set(HAVE__PROGNAME 0)
endif ()

if (NOT HAVE_GETEXECNAME)
  set(HAVE_GETEXECNAME 0)
endif ()

if (NOT HAVE___ARGC)
  set (HAVE__ARGC 0)
endif ()

if (NOT HAVE___ARGV)
  set(HAVE__ARGV 0)
endif ()
