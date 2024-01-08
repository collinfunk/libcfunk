
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)

# Generate <iconv.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ICONV_H "1" CACHE STRING "")

check_include_file("iconv.h" HAVE_ICONV_H)

if (HAVE_ICONV_H)
  find_file(ICONV_H_PATH NAMES "iconv.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "iconv.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("iconv_t" ICONV_T)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-iconv-h.cmake)
endif ()

