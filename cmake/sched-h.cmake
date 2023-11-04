
include_guard(GLOBAL)

# Generate <sched.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SCHED_H "1" CACHE STRING "")

check_include_file("sched.h" HAVE_SCHED_H)

if (HAVE_SCHED_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sched.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("struct sched_param" STRUCT_SCHED_PARAM)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sched-h.cmake)
endif ()

