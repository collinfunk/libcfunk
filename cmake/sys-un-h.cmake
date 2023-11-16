
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)

# Generate <sys/un.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_UN_H "1" CACHE STRING "")

# The <sys/un.h> file often requires some headers to compile.
set(SYS_UN_H_INCLUDES "")
if (HAVE_SYS_SOCKET_H)
  list(APPEND SYS_UN_H_INCLUDES "sys/socket.h")
endif ()
if (HAVE_WINSOCK2_H)
  list(APPEND SYS_UN_H_INCLUDES "winsock2.h")
endif ()
if (HAVE_WS2TCPIP_H)
  list(APPEND SYS_UN_H_INCLUDES "ws2tcpip.h")
endif ()

# Check for the files.
check_include_files("${SYS_UN_H_INCLUDES};sys/un.h" HAVE_SYS_UN_H)
check_include_files("${SYS_UN_H_INCLUDES};afunix.h" HAVE_AFUNIX_H)

# Append the header so we can check for types.
if (HAVE_SYS_UN_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/un.h")
endif ()
if (HAVE_AFUNIX_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "afunix.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("struct sockaddr_un" STRUCT_SOCKADDR_UN)

# Clear the local variable.
unset(SYS_UN_H_INCLUDES)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-un-h.cmake)
endif ()

