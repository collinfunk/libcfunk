
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)

# Generate <search.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SEARCH_H "1" CACHE STRING "")

check_include_file("search.h" HAVE_SEARCH_H)

if (HAVE_SEARCH_H)
  find_file(SEARCH_H_PATH NAMES "search.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "search.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct qelem" STRUCT_QELEM)
  check_type_size("struct entry" STRUCT_ENTRY)
  check_type_size("ENTRY" ENTRY)
  check_type_size("ACTION" ACTION)
  check_type_size("VISIT" VISIT)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-search-h.cmake)
endif ()

