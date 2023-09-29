
include_guard(GLOBAL)

# Check if the compiler supports the C23 nullptr constant.
check_c_compiles("

int
main (void)
{
  void *ptr = nullptr;
  return 0;
}
" HAVE_C23_NULLPTR)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-nullptr.cmake)
endif ()
