
include_guard(GLOBAL)

# Generate <wchar.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_WCHAR_H "1" CACHE STRING "")

check_include_file("wchar.h" HAVE_WCHAR_H)
check_include_file("wctype.h" HAVE_WCTYPE_H)

if (HAVE_WCHAR_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "wchar.h")
endif ()

if (HAVE_WCTYPE_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "wctype.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("mbstate_t" MBSTATE_T)
check_type_size("wctype_t" WCTYPE_T)
check_type_size("wint_t" WINT_T)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-wchar-h.cmake)
endif ()

