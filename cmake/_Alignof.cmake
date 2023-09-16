
include_guard(GLOBAL)

# Check for C11 _Alignof.
check_c_source_compiles("

int
main (void)
{
  int value = _Alignof (char);
  return 0;
}
" HAVE_C11__ALIGNOF)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/_Alignof.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-_Alignof.cmake)
endif ()
