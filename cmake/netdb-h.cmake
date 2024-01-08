
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/netinet-in-h.cmake)

# Generate <netdb.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_NETDB_H "1" CACHE STRING "")

check_include_file("netdb.h" HAVE_NETDB_H)

if (HAVE_NETDB_H)
  find_file(NETDB_H_PATH NAMES "netdb.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "netdb.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("struct hostent" STRUCT_HOSTENT)
check_type_size("struct netent" STRUCT_NETENT)
check_type_size("struct protoent" STRUCT_PROTOENT)
check_type_size("struct servent" STRUCT_SERVENT)
check_type_size("struct addrinfo" STRUCT_ADDRINFO)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-netdb-h.cmake)
endif ()

