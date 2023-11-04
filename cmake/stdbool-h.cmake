
include_guard(GLOBAL)

# Generate <stdbool.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDBOOL_H "1" CACHE STRING "")

check_include_file("stdbool.h" HAVE_STDBOOL_H)

# Check if compiler is C23 and has true, false, and bool as keywords.
check_c_source_compiles("

int
main (void)
{
  bool a = true;
  bool b = false;

  return a != b ? 0 : 1;
}
" HAVE_C23_BOOL)

# Check if the compiler is C99 and has the _Bool keyword.
check_c_source_compiles("

int
main (void)
{
  _Bool a = 1;
  _Bool b = 0;

  return a != b ? 0 : 1;
}
" HAVE_C99_BOOL)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdbool-h.cmake)
endif ()

