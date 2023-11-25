
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

# Generate <uchar.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_UCHAR_H "1" CACHE STRING "")

check_include_file("uchar.h" HAVE_UCHAR_H)

if (HAVE_UCHAR_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "uchar.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

# Check for types.
check_type_size("char8_t" CHAR8_T)
check_type_size("char16_t" CHAR16_T)
check_type_size("char32_t" CHAR32_T)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-uchar-h.cmake)
endif ()

