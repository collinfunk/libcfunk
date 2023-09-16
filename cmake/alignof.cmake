
include_guard(GLOBAL)

# If `alignof' is needed, then we use `_Alignof'.
include($CACHE{LIBCFUNK_MODULE_DIR}/_Alignof.cmake)

# Check for C23 alignof.
check_c_source_compiles("

int
main (void)
{
  int value = alignof (char);
  return 0;
}
" HAVE_C23_ALIGNOF)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/alignof.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-alignof.cmake)
endif ()
