
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

# Generate <inttypes.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_INTTYPES_H "1" CACHE STRING "")

check_include_file("inttypes.h" HAVE_INTTYPES_H)

if (HAVE_INTTYPES_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "inttypes.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("imaxdiv_t" IMAXDIV_T)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-inttypes-h.cmake)
endif ()

