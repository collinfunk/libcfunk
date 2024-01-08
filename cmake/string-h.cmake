
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)

# Generate <string.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STRING_H "1" CACHE STRING "")

check_include_file("string.h" HAVE_STRING_H)
check_include_file("strings.h" HAVE_STRINGS_H)

if (HAVE_STRING_H)
  find_file(STRING_H_PATH NAMES "string.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-string-h.cmake)
endif ()

