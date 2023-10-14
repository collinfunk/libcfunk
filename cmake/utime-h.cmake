
include_guard(GLOBAL)

# Generate <utime.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_UTIME_H "1" CACHE INTERNAL "")

check_include_file("utime.h" HAVE_UTIME_H)
check_include_file("sys/utime.h" HAVE_SYS_UTIME_H)

if (HAVE_UTIME_H OR HAVE_SYS_UTIME_H)
  if (HAVE_UTIME_H)
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "utime.h")
  endif ()
  if (HAVE_SYS_UTIME_H)
     list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/utime.h")
  endif ()
  check_type_size("struct utimbuf" STRUCT_UTIMBUF)
  check_type_size("struct _utimbuf" STRUCT__UTIMBUF)
  if (HAVE_UTIME_H)
    list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "utime.h")
  endif ()
  if (HAVE_SYS_UTIME_H)
     list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "sys/utime.h")
   endif ()
else ()
  set(HAVE_STRUCT_UTIMBUF "" CACHE INTERNAL "")
  set(HAVE_STRUCT__UTIMBUF "" CACHE INTERNAL "")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-utime-h.cmake)
endif ()
