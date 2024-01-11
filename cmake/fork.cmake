
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

# Check for 'fork' in libc, librt, or libposix4.
if (HAVE_UNISTD_H)
  check_symbol_exists("fork" "unistd.h" HAVE_FORK_IN_LIBC)
  if (NOT HAVE_FORK_IN_LIBC)
    check_library_exists("rt" "fork" "" HAVE_FORK_IN_LIBRT)
    if (HAVE_FORK_IN_LIBRT)
      target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "rt")
      list(APPEND CMAKE_REQUIRED_LIBRARIES "rt")
      list(REMOVE_DUPLICATES CMAKE_REQUIRED_LIBRARIES)
    else ()
      check_library_exists("posix4" "fork" "" HAVE_FORK_IN_LIBPOSIX4)
      if (HAVE_FORK_IN_LIBPOSIX4)
        target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "posix4")
        list(APPEND CMAKE_REQUIRED_LIBRARIES "posix4")
        list(REMOVE_DUPLICATES CMAKE_REQUIRED_LIBRARIES)
      endif ()
    endif ()
  endif ()
  if (HAVE_FORK_IN_LIBC OR HAVE_FORK_IN_LIBRT OR HAVE_FORK_IN_LIBPOSIX4)
    set(HAVE_FORK "1" CACHE STRING "")
  endif ()
endif ()

# Don't include this on Windows. We can't do much if we don't have it.
if (NOT HAVE_FORK)
  message(FATAL_ERROR "No implementation of 'fork' for your systems.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fork.cmake)
endif ()

