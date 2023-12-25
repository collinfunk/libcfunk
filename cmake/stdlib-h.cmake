
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-wait-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

# Generate <stdlib.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDLIB_H "1" CACHE STRING "")

check_include_file("stdlib.h" HAVE_STDLIB_H)

if (HAVE_STDLIB_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "stdlib.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct random_data" STRUCT_RANDOM_DATA)
  check_type_size("div_t" DIV_T)
  check_type_size("ldiv_t" LDIV_T)
  check_type_size("lldiv_t" LLDIV_T)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdlib-h.cmake)
endif ()

