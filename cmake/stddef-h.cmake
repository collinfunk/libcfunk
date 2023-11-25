
include_guard(GLOBAL)

# Generate <stddef.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDDEF_H "1" CACHE STRING "")

check_include_file("stddef.h" HAVE_STDDEF_H)

check_type_size("ptrdiff_t" PTRDIFF_T)
check_type_size("size_t" SIZE_T)
check_type_size("max_align_t" MAX_ALIGN_T)
check_type_size("wchar_t" WCHAR_T)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stddef-h.cmake)
endif ()

