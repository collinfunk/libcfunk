
include_guard(GLOBAL)

# Generate <ar.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_AR_H "1" CACHE STRING "")

check_include_file("ar.h" HAVE_AR_H)

if (HAVE_AR_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "ar.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct ar_hdr" STRUCT_AR_HDR)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ar-h.cmake)
endif ()

