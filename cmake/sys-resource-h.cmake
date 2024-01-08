
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-time-h.cmake)

# Generate <sys/resource.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_RESOURCE_H "1" CACHE STRING "")

check_include_file("sys/resource.h" HAVE_SYS_RESOURCE_H)

if (HAVE_SYS_RESOURCE_H)
  find_file(SYS_RESOURCE_H_PATH NAMES "sys/resource.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/resource.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("rlim_t" RLIM_T)
check_type_size("struct rlimit" STRUCT_RLIMIT)
check_type_size("struct rusage" STRUCT_RUSAGE)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-resource-h.cmake)
endif ()

