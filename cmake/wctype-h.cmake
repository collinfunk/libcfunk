
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

# Generate <wctype.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_WCTYPE_H "1" CACHE STRING "")

check_include_file("wctype.h" HAVE_WCTYPE_H)
if (HAVE_WCTYPE_H)
  find_file(WCTYPE_H_PATH NAMES "wctype.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-wctype-h.cmake)
endif ()

