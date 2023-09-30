
include_guard(GLOBAL)

# If `alignas' is needed, then we use `_Alignas'.
include($CACHE{LIBCFUNK_MODULE_DIR}/_Alignas.cmake)

# Check for C22 alignas.
check_c_source_compiles("

int
main (void)
{
  alignas (128) int value = 0;
  return 0;
}
" HAVE_C23_ALIGNAS)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/alignas.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-alignas.cmake)
endif ()
