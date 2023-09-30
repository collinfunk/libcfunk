
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/offsetof.cmake)

# Check for C11 _Alignas.
check_c_source_compiles("

int
main (void)
{
  _Alignas (128) int value = 0;
  return 0;
}
" HAVE_C11__ALIGNAS)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/_Alignas.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-_Alignas.cmake)
endif ()
