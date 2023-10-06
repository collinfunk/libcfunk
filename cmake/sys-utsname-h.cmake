
include_guard(GLOBAL)

# Generate <sys/utsname.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_UTSNAME_H "1" CACHE INTERNAL "")

check_include_file("sys/utsname.h" HAVE_SYS_UTSNAME_H)

if (HAVE_SYS_UTSNAME_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/utsname.h")
  check_type_size("struct utsname" STRUCT_UTSNAME)
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "sys/utsname.h")
else ()
  set(HAVE_STRUCT_UTSNAME "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_UNAME "0" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-utsname-h.cmake)
endif ()
