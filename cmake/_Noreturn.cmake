
include_guard(GLOBAL)

# Check for C11 _Noreturn.
check_c_compiles("

#include <stdlib.h>

_Noreturn void exit_program (void);

int
main (void)
{
  exit_program ();
}

_Noreturn void
exit_program (void)
{
  exit (0);
}
" HAVE_C11__NORETURN)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/_Noreturn.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-_Noreturn.cmake)
endif ()
