
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/dirent-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

check_include_file("sys/types.h" HAVE_SYS_TYPES_H)

set(DIRFD_HEADERS)

if (HAVE_SYS_TYPES_H)
  list(APPEND DIRFD_HEADERS "sys/types.h")
endif ()

if (HAVE_DIRENT_H)
  list(APPEND DIRFD_HEADERS "dirent.h")
  check_symbol_exists("dirfd" "dirent.h" HAVE_DIRFD)
endif ()

set(LIBCFUNK_DECLARE_DIRFD "1" CACHE STRING "")

if (NOT HAVE_DIRFD)
  check_struct_has_member("DIR" "fd" "${DIRFD_HEADERS}" HAVE_DIR_FD)
  check_struct_has_member("DIR" "d_fd" "${DIRFD_HEADERS}" HAVE_DIR_D_FD)
  check_struct_has_member("DIR" "dd_fd" "${DIRFD_HEADERS}" HAVE_DIR_DD_FD)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/dirfd.c
  )
endif ()

unset(DIRFD_HEADERS)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-dirfd.cmake)
endif ()
