
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-time-h.cmake)

# Generate <sys/resource.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_RESOURCE_H "1" CACHE INTERNAL "")

check_include_file("sys/resource.h" HAVE_SYS_RESOURCE_H)

if (HAVE_SYS_RESOURCE_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/resource.h")
  check_type_size("rlim_t" RLIM_T)
  check_type_size("struct rlimit" STRUCT_RLIMIT)
  check_type_size("struct rusage" STRUCT_RUSAGE)
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "sys/resource.h")
else ()
  set(HAVE_RLIM_T "" CACHE INTERNAL "")
  set(HAVE_STRUCT_RLIMIT "" CACHE INTERNAL "")
  set(HAVE_STRUCT_RUSAGE "" CACHE INTERNAL "")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-resource-h.cmake)
endif ()

