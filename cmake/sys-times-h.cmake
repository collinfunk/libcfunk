
include_guard(GLOBAL)

# Generate <sys/times.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_TIMES_H "1" CACHE INTERNAL "")

check_include_file("sys/times.h" HAVE_SYS_TIMES_H)

if (HAVE_SYS_TIMES_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/times.h")
  check_type_size("struct tms" STRUCT_TMS)
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "sys/times.h")
else ()
  set(HAVE_STRUCT_TMS "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_TIMES "0" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-times-h.cmake)
endif ()

