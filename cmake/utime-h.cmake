
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <utime.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_UTIME_H "1" CACHE STRING "")

# Check for 'utime.h' or 'sys/utime.h'.
check_include_file("utime.h" HAVE_UTIME_H)
if (HAVE_UTIME_H)
  find_file(UTIME_H_PATH NAMES "utime.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "utime.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
else ()
  check_include_file("sys/utime.h" HAVE_SYS_UTIME_H)
  if (HAVE_SYS_UTIME_H)
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/utime.h")
    list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  endif ()
endif ()

# Check for 'struct utimbuf' or 'struct _utimbuf'.
if (HAVE_UTIME_H OR HAVE_SYS_UTIME_H)
  check_type_size("struct utimbuf" STRUCT_UTIMBUF)
  if (NOT HAVE_STRUCT_UTIMBUF)
    check_type_size("struct _utimbuf" STRUCT__UTIMBUF)
  endif ()
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utime-h.cmake)
endif ()

