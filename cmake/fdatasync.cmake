
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("fdatasync" "unistd.h" HAVE_FDATASYNC_IN_LIBC)
  if (NOT HAVE_FDATASYNC_IN_LIBC)
    check_library_exists("rt" "fdatasync" "" HAVE_FDATASYNC_IN_LIBRT)
    if (HAVE_FDATASYNC_IN_LIBRT)
      target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "rt")
      list(APPEND CMAKE_REQUIRED_LIBRARIES "rt")
      list(REMOVE_DUPLICATES CMAKE_REQUIRED_LIBRARIES)
    else ()
      check_library_exists("posix4" "fdatasync" "" HAVE_FDATASYNC_IN_LIBPOSIX4)
      if (HAVE_FDATASYNC_IN_LIBPOSIX4)
        target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "posix4")
        list(APPEND CMAKE_REQUIRED_LIBRARIES "posix4")
        list(REMOVE_DUPLICATES CMAKE_REQUIRED_LIBRARIES)
      endif ()
    endif ()
  endif ()
  if (HAVE_FDATASYNC_IN_LIBC OR HAVE_FDATASYNC_IN_LIBRT OR  HAVE_FDATASYNC_IN_LIBPOSIX4)
    set(HAVE_FDATASYNC "1" CACHE STRING "")
  endif ()
endif ()

set(LIBCFUNK_DECLARE_FDATASYNC "1" CACHE STRING "")

if (NOT HAVE_FDATASYNC)
  include($CACHE{LIBCFUNK_MODULE_DIR}/fsync.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fdatasync.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fdatasync.cmake)
endif ()

