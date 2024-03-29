
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-uio-h.cmake)

# Generate <sys/socket.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_SOCKET_H "1" CACHE STRING "")

# Headers
check_include_file("sys/socket.h" HAVE_SYS_SOCKET_H)
check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("io.h" HAVE_IO_H)

if (HAVE_SYS_SOCKET_H)
  find_file(SYS_SOCKET_H_PATH NAMES "sys/socket.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/socket.h")
  find_library(SOCKET_LIBRARY "socket")
  if (SOCKET_LIBRARY)
    target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "${SOCKET_LIBRARY}")
    list(APPEND CMAKE_REQUIRED_LIBRARIES "${SOCKET_LIBRARY}")
  endif ()
endif ()

# Check for Windows-specific headers and libraries.
if (HAVE_WINDOWS_H)
  check_include_files("windows.h;winsock2.h" HAVE_WINSOCK2_H)
  check_include_files("windows.h;ws2tcpip.h" HAVE_WS2TCPIP_H)
  if (HAVE_WINSOCK2_H)
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "winsock2.h")
  endif ()
  if (HAVE_WS2TCPIP_H)
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "ws2tcpip.h")
  endif ()
  find_library(WS2_32_LIBRARY "ws2_32" REQUIRED)
  target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "${WS2_32_LIBRARY}")
  list(APPEND CMAKE_REQUIRED_LIBRARIES "${WS2_32_LIBRARY}")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("socklen_t" SOCKETLEN_T)
check_type_size("sa_family_t" SA_FAMILY_T)
check_type_size("struct sockaddr" STRUCT_SOCKADDR)
check_type_size("struct sockaddr_storage" STRUCT_SOCKADDR_STORAGE)
check_type_size("struct cmsghdr" STRUCT_CMSGHDR)
check_type_size("struct linger" STRUCT_LINGER)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-socket-h.cmake)
endif ()

