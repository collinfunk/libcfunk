
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/netdb-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)

set(GAI_STRERROR_INCLUDES "")
set(GAI_STRERROR_SOURCE_HEADER "")

if (HAVE_SYS_SOCKET_H)
  list(APPEND GAI_STRERROR_INCLUDES "sys/socket.h")
endif ()

if (HAVE_NETDB_H)
  list(APPEND GAI_STRERROR_INCLUDES "netdb.h")
endif ()

if (HAVE_WINSOCK2_H)
  list(APPEND GAI_STRERROR_INCLUDES "winsock2.h")
endif ()

if (HAVE_WS2TCPIP_H)
  list(APPEND GAI_STRERROR_INCLUDES "ws2tcpip.h")
endif ()

foreach (header ${GAI_STRERROR_INCLUDES})
  string(APPEND GAI_STRERROR_SOURCE_HEADER "#include <${header}>\n")
endforeach ()

# Check for the function 'gai_strerror'.
check_symbol_exists("gai_strerror" "${GAI_STRERROR_INCLUDES}" HAVE_GAI_STRERROR)
check_symbol_exists("gai_strerrorA" "${GAI_STRERROR_INCLUDES}" HAVE_GAI_STRERRORA)

# Check that it returns 'const char *' and not 'char *'.
if (HAVE_GAI_STRERROR)
  check_c_source_compiles("
  #include <stddef.h>
  ${GAI_STRERROR_SOURCE_HEADER}

  const char *gai_strerror (int error_code);

  int
  main (void)
  {
    return 0;
  }
  " GAI_STRERROR_RETURNS_CONST_CHAR)
endif ()

# Clear variables from parent CMakeLists.txt
unset(GAI_STRERROR_INCLUDES)
unset(GAI_STRERROR_SOURCE_HEADER)

# Replace a function that returns 'char *'
if (NOT GAI_STRERROR_RETURNS_CONST_CHAR)
  set(LIBCFUNK_REPLACE_GAI_STRERROR "1" CACHE STRING "")
endif ()

if (LIBCFUNK_REPLACE_GAI_STRERROR OR NOT HAVE_GAI_STRERROR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/gai_strerror.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-gai_strerror.cmake)
endif ()
