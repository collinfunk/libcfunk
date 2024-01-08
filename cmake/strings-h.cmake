
include_guard(GLOBAL)

# Generate <strings.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STRINGS_H "1" CACHE STRING "")

check_include_file("string.h" HAVE_STRING_H)
check_include_file("strings.h" HAVE_STRINGS_H)

if (HAVE_STRINGS_H)
  find_file(STRINGS_H_PATH NAMES "strings.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strings-h.cmake)
endif ()

