
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <sys/uio.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_UIO_H "1" CACHE INTERNAL "")

check_include_file("sys/uio.h" HAVE_SYS_UIO_H)

if (HAVE_SYS_UIO_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/uio.h")
  check_type_size("struct iovec" STRUCT_IOVEC)
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "sys/uio.h")
else ()
  set(HAVE_STRUCT_IOVEC "" CACHE INTERNAL "")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-uio-h.cmake)
endif ()

