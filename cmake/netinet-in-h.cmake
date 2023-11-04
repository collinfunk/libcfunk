
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)

# Generate <netinet/in.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_NETINET_IN_H "1" CACHE STRING "")

check_include_file("netinet/in.h" HAVE_NETINET_IN_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-netinet-in-h.cmake)
endif ()

