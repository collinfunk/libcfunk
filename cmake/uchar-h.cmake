
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

# Generate <uchar.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_UCHAR_H "1" CACHE INTERNAL "")

check_include_file("uchar.h" HAVE_UCHAR_H)

# Check for types.
if (HAVE_UCHAR_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "uchar.h")
  check_type_size("char8_t" CHAR8_T)
  check_type_size("char16_t" CHAR16_T)
  check_type_size("char32_t" CHAR32_T)
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "uchar.h")
else ()
  set(HAVE_CHAR8_T "" CACHE INTERNAL "")
  set(HAVE_CHAR16_T "" CACHE INTERNAL "")
  set(HAVE_CHAR32_T "" CACHE INTERNAL "")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-uchar-h.cmake)
endif ()

