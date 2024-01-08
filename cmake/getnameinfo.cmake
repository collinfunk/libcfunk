
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/netdb-h.cmake)

if (HAVE_SYS_SOCKET_H OR HAVE_NETDB_H OR HAVE_WINSOCK2_H OR HAVE_WS2TCPIP_H)
  set(GETNAMEINFO_INCLUDES "")
  if (HAVE_SYS_SOCKET_H)
    list(APPEND GETNAMEINFO_INCLUDES "sys/socket.h")
  endif ()
  if (HAVE_NETDB_H)
    list(APPEND GETNAMEINFO_INCLUDES "netdb.h")
  endif ()
  if (HAVE_WINSOCK2_H)
    list(APPEND GETNAMEINFO_INCLUDES "winsock2.h")
  endif ()
  if (HAVE_WS2TCPIP_H)
    list(APPEND GETNAMEINFO_INCLUDES "ws2tcpip.h")
  endif ()
  check_symbol_exists("getnameinfo" "${GETNAMEINFO_INCLUDES}" HAVE_GETNAMEINFO)
  unset(GETNAMEINFO_INCLUDES)
endif ()

# TODO
if (NOT HAVE_GETNAMEINFO)
  message(FATAL_ERROR "No implementation of 'getnameinfo' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getnameinfo.cmake)
endif ()

