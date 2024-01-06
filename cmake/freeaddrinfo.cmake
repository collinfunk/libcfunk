
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/netdb-h.cmake)

if (HAVE_SYS_SOCKET_H OR HAVE_NETDB_H OR HAVE_WINSOCK2_H OR HAVE_WS2TCPIP_H)
  set(FREEADDRINFO_INCLUDES "")
  if (HAVE_SYS_SOCKET_H)
    list(APPEND FREEADDRINFO_INCLUDES "sys/socket.h")
  endif ()
  if (HAVE_NETDB_H)
    list(APPEND FREEADDRINFO_INCLUDES "netdb.h")
  endif ()
  if (HAVE_WINSOCK2_H)
    list(APPEND FREEADDRINFO_INCLUDES "winsock2.h")
  endif ()
  if (HAVE_WS2TCPIP_H)
    list(APPEND FREEADDRINFO_INCLUDES "ws2tcpip.h")
  endif ()
  check_symbol_exists("freeaddrinfo" "${FREEADDRINFO_INCLUDES}" HAVE_FREEADDRINFO)
  unset(FREEADDRINFO_INCLUDES)
endif ()

# TODO
if (NOT HAVE_FREEADDRINFO)
  message(FATAL_ERROR "No implementation of 'freeaddrinfo' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-freeaddrinfo.cmake)
endif ()

