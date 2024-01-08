
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

# Generate <netinet/in.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_NETINET_IN_H "1" CACHE STRING "")

check_include_file("netinet/in.h" HAVE_NETINET_IN_H)

if (HAVE_NETINET_IN_H)
  find_file(NETINET_IN_H_PATH NAMES "netinet/in.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "netinet/in.h")
endif ()

check_type_size("in_port_t" IN_PORT_T)
check_type_size("in_addr_t" IN_ADDR_T)
check_type_size("struct in_addr" STRUCT_IN_ADDR)
check_type_size("struct sockaddr_in" STRUCT_SOCKADDR_IN)
check_type_size("struct in6_addr" STRUCT_IN6_ADDR)
check_type_size("struct sockaddr_in6" STRUCT_SOCKADDR_IN6)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-netinet-in-h.cmake)
endif ()

