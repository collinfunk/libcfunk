
include_guard(GLOBAL)

# Test if the compiler supports '__func__' as defined by C99.
check_c_source_compiles("
int
main (void)
{
  static const char *str = __func__;
  return 0;
}
" HAVE_C99__FUNC__)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/__func__.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-__func__.cmake)
endif ()

