
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)

# Generate <netdb.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_NETDB_H "1" CACHE STRING "")

check_include_file("netdb.h" HAVE_NETDB_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-netdb-h.cmake)
endif ()

