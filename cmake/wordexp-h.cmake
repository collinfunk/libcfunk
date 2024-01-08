
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)

# Generate <wordexp.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_WORDEXP_H "1" CACHE STRING "")

check_include_file("wordexp.h" HAVE_WORDEXP_H)

if (HAVE_WORDEXP_H)
  find_file(WORDEXP_H_PATH NAMES "wordexp.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "wordexp.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("wordexp_t" WORDEXP_T)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-wordexp-h.cmake)
endif ()

