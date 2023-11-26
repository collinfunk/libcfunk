
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <utime.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_UTIME_H "1" CACHE STRING "")

check_include_file("utime.h" HAVE_UTIME_H)
check_include_file("sys/utime.h" HAVE_SYS_UTIME_H)

if (HAVE_UTIME_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "utime.h")
endif ()

if (HAVE_SYS_UTIME_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/utime.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("struct utimbuf" STRUCT_UTIMBUF)
check_type_size("struct _utimbuf" STRUCT__UTIMBUF)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utime-h.cmake)
endif ()
