
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <sched.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SCHED_H "1" CACHE STRING "")

check_include_file("sched.h" HAVE_SCHED_H)

if (HAVE_SCHED_H)
  find_file(SCHED_H_PATH NAMES "sched.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sched.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("struct sched_param" STRUCT_SCHED_PARAM)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sched-h.cmake)
endif ()

