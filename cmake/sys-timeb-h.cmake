
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <sys/timeb.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_TIMEB_H "1" CACHE STRING "")

check_include_file("sys/timeb.h" HAVE_SYS_TIMEB_H)

if (HAVE_SYS_TIMEB_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/timeb.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct timeb" STRUCT_TIMEB)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-timeb-h.cmake)
endif ()

