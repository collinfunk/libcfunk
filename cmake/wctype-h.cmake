
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

# Generate <wctype.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_WCTYPE_H "1" CACHE STRING "")

check_include_file("wchar.h" HAVE_WCHAR_H)
check_include_file("wctype.h" HAVE_WCTYPE_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-wctype-h.cmake)
endif ()

