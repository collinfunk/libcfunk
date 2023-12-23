
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

# Generate <sys/times.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_TIMES_H "1" CACHE STRING "")

check_include_file("sys/times.h" HAVE_SYS_TIMES_H)

if (HAVE_SYS_TIMES_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/times.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct tms" STRUCT_TMS)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-times-h.cmake)
endif ()

