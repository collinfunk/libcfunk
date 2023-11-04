
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-socket-h.cmake)

# Generate <arpa/inet.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ARPA_INET_H "1" CACHE STRING "")

check_include_file("arpa/inet.h" HAVE_ARPA_INET_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-arpa-inet-h.cmake)
endif ()

