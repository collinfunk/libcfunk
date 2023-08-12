
include_guard(GLOBAL)

# Check if the compiler supports #include_next.
# The boolean result is stored in HAS_INCLUDE_NEXT_DIRECTIVE.
check_c_source_compiles("
#include_next <stdlib.h>

int
main (void)
{
  return 0;
}"
HAVE_INCLUDE_NEXT_DIRECTIVE)

