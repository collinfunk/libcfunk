
include_guard(GLOBAL)

# Generate <stdio_ext.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDIO_EXT_H "1" CACHE STRING "")

check_include_file("stdio.h" HAVE_STDIO_H)
check_include_file("stdio_ext.h" HAVE_STDIO_EXT_H)
check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_STDIO_EXT_H)
  find_file(STDIO_EXT_H_PATH NAMES "stdio_ext.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (HAVE_STDIO_H)
  check_struct_has_member("FILE" "_bufsiz" "stdio.h" HAVE_FILE__BUFSIZ)
  check_struct_has_member("FILE" "_ptr" "stdio.h" HAVE_FILE__PTR)
  check_struct_has_member("FILE" "_base" "stdio.h" HAVE_FILE__BASE)
  check_struct_has_member("FILE" "_cnt" "stdio.h" HAVE_FILE__CNT)
  check_struct_has_member("FILE" "_flag" "stdio.h" HAVE_FILE__FLAG)
  check_struct_has_member("FILE" "_flags" "stdio.h" HAVE_FILE__FLAGS)
  check_struct_has_member("FILE" "_bf" "stdio.h" HAVE_FILE__BF)
  check_struct_has_member("FILE" "_p" "stdio.h" HAVE_FILE__P)
  if (HAVE_FILE__BF)
    check_struct_has_member("FILE" "_bf._base" "stdio.h" HAVE_FILE__BF__BASE)
    check_struct_has_member("FILE" "_bf._size" "stdio.h" HAVE_FILE__BF__SIZE)
  endif ()
  check_struct_has_member("FILE" "_IO_buf_end" "stdio.h" HAVE_FILE__IO_BUF_END)
  check_struct_has_member("FILE" "_IO_buf_base" "stdio.h" HAVE_FILE__IO_BUF_BASE)
  check_struct_has_member("FILE" "_IO_write_ptr" "stdio.h" HAVE_FILE__IO_WRITE_PTR)
  check_struct_has_member("FILE" "_IO_write_base" "stdio.h" HAVE_FILE__IO_WRITE_BASE)
endif ()

if (LIBCFUNK_MODULE_DIR)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdio-ext-h.cmake)
endif ()

