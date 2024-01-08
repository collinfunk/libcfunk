
include_guard(GLOBAL)

# Generate <poll.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_POLL_H "1" CACHE STRING "")

check_include_file("poll.h" HAVE_POLL_H)
check_include_file("winsock2.h" HAVE_WINSOCK2_H)

# Check for types.
if (HAVE_POLL_H OR HAVE_WINSOCK2_H)
  if (HAVE_POLL_H)
    find_file(POLL_H_PATH NAMES "poll.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "poll.h")
  endif ()
  if (HAVE_WINSOCK2_H)
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "winsock2.h")
  endif ()
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct pollfd" STRUCT_POLLFD)
  check_type_size("nfds_t" NFDS_T)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-poll-h.cmake)
endif ()

